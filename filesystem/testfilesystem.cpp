/*
 * testfilesystem.cpp
 *
 *  Created on: 2015年10月6日
 *      Author: lql
 *          QQ: 896849432
 * 各位同学十分抱歉，之前给的样例程序不支持同时打开多个文件
 * 是因为初始化没有做，现在的程序加上了初始化（main函数中的第一行）
 * 已经可以支持多个文件的维护
 *
 * 但是还是建议大家只维护一个文件，因为首先没有必要，我们可以把数据库中
 * 的索引和数据都放在同一个文件中，当我们开启一个数据库时，就关掉上一个
 * 其次，多个文件就要对应多个fileID，在BufPageManager中是利用一个hash函数
 * 将(fileID,pageID)映射为一个整数，但由于我设计的hash函数过于简单，就是fileID和
 * pageID的和，所以不同文件的页很有可能映射为同一个数，增加了hash的碰撞率，影响效率
 * 
 * 还有非常重要的一点，BufType b = bpm->allocPage(...)
 * 在利用上述allocPage函数或者getPage函数获得指向申请缓存的指针后，
 * 不要自行进行类似的delete[] b操作，内存的申请和释放都在BufPageManager中做好
 * 如果自行进行类似free(b)或者delete[] b的操作，可能会导致严重错误
 */
#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "recordmaneger/RecordManager.h"
#include "indexmanager/IndexManager.h"
#include "utils/pagedef.h"
#include <iostream>
#include "parse/SQLParser.h"
#include "parse/sqlhelper.h"
#include "parse/sql/statements.h"
#include "systemManager/DatabaseSystem.h"
#include <sys/time.h>
using namespace std;
using namespace hsql;

int test_parse(int argc, char **argv){
    DatabaseSystem myDB;
    string SQL = "sql>";
    string SQL_CONTINUE = "--->";
    cout<<SQL;
    if (argv[1][0]=='1'){
        string sql_stmt;
        char temp;
        char input[4]={' ',' ',' ',' '};
        bool isFile = false;
        while(scanf("%c",&temp))
        {
            for(int i=3;i>0;--i){
                input[i-1] = input[i];
            }
            input[3]=temp;
            if(temp=='\n') {
                if(sql_stmt[sql_stmt.length()-1]==';') {
                    if (isFile) {
                        isFile = false;
                        time_t start,finish;
                        start = clock();
                        myDB.readSQLfile(sql_stmt.substr(5, sql_stmt.length() - 6));
                        finish = clock();
                        cout<<"file exe ok, cost time:"<<((finish-start) / 1000.0)<<" ms"<<endl;
                        sql_stmt = "";
                    } else {
                        time_t start,finish;
                        start = clock();
                        myDB.readSQL(sql_stmt);
                        finish = clock();
                        cout<<"sql exe ok, cost time:"<<((finish-start) / 1000.0)<<" ms"<<endl;
                        sql_stmt = "";
                    }
                    cout << SQL;
                }
                else {
                    cout<<SQL_CONTINUE;
                }
            }
            else if(temp!='\r'){
                sql_stmt+=temp;
                if(sql_stmt=="quit")
                    return 0;
                if(sql_stmt=="file")
                    isFile = true;
            }
        }
    }
    else {
        cout<<"fail to exe"<<endl;
    }
}


void only_test_index(){
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);

    IndexManager* indexManager = new IndexManager(fm,bpm);
    IX_IndexHandle ixIndexHandle;
    char a[] = "test26.txt";
//    rm->createFile(a,24);
//    RM_FileHandle handle;
//    rm->openFile(a,handle);
//    printf("open file: %s ok \n",a);
    RID rid;
    rid.pid = 1;
    rid.sid = 5;
    char key1 = 31;
    char key2 = 32;
//    indexManager-> CreateIndex(a,0,INT,4);

    indexManager-> OpenIndex(a,ixIndexHandle);
    ixIndexHandle.InsertEntry(&key1,rid);
    ixIndexHandle.InsertEntry(&key2,rid);
    Node node;
    Pointer pointer;
    int type,tag;
    ixIndexHandle.searchEntry(&key1,pointer,type,tag);
    ixIndexHandle.close();
    printf("search node info: pid:%d ; offset:%d\n",pointer.pid,pointer.offset);
}

void test2() {
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    RecordManager* rm = new RecordManager(fm,bpm);
    char a[] = "test25.txt";
    RM_FileAttr * attrType = new RM_FileAttr();
    rm->createFile(a,attrType);
    RM_FileHandle handle;
    rm->openFile(a,handle);
    printf("open file: %s ok \n",a);
/*
    RID old;
    old.pid = 1;
    old.sid = 5;
    handle.deleteRec(old);
    printf("delete rid<%d,%d> ok \n",old.pid,old.sid);
    */

    RID rid;
    BufType data = new unsigned int[10];
    data[0] = 20;
    data[1] = 20;
    handle.insertRec(data,rid);
    printf("insert rid<%d,%d> , data[0]: %d ok \n",rid.pid,rid.sid,data[0]);

    Record rec;
    handle.getRec(rid,rec);
    rec.print();

}

void test1() {
    std::cout<< sizeof(bool) <<std::endl;
    MyBitMap::initConst();   //新加的初始化
    FileManager* fm = new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    fm->createFile("testfile.txt"); //新建文件
    fm->createFile("testfile2.txt");
    int fileID, f2;
    fm->openFile("testfile.txt", fileID); //打开文件，fileID是返回的文件id
    fm->openFile("testfile2.txt", f2);
    for (int pageID = 0; pageID < 1000; ++ pageID) {
        int index;
        //为pageID获取一个缓存页
        BufType b = bpm->allocPage(fileID, pageID, index, false);
        //注意，在allocPage或者getPage后，千万不要进行delete[] b这样的操作
        //内存的分配和管理都在BufPageManager中做好，不需要关心，如果自行释放会导致问题
        b[0] = pageID; //对缓存页进行写操作
        b[1] = fileID;
        bpm->markDirty(index); //标记脏页
        //在重新调用allocPage获取另一个页的数据时并没有将原先b指向的内存释放掉
        //因为内存管理都在BufPageManager中做好了
        b = bpm->allocPage(f2, pageID, index, false);
        b[0] = pageID;
        b[1] = f2;
        bpm->markDirty(index);
    }
    for (int pageID = 0; pageID < 1000; ++ pageID) {
        int index;
        //为pageID获取一个缓存页
        BufType b = bpm->getPage(fileID, pageID, index);
        //注意，在allocPage或者getPage后，千万不要进行delete[] b这样的操作
        //内存的分配和管理都在BufPageManager中做好，不需要关心，如果自行释放会导致问题
        cout << b[0] << ":" << b[1] << endl; 		//读取缓存页中第一个整数
        bpm->access(index); //标记访问
        b = bpm->getPage(f2, pageID, index);
        cout << b[0] << ":" << b[1] << endl;
        bpm->access(index);
    }
    bpm->close();
    //程序结束前可以调用BufPageManager的某个函数将缓存中的内容写回
    //具体的函数大家可以看看ppt或者程序的注释
    return ;
}

int main(int argc, char **argv) {
//    only_test_index();
//    test2();
    test_parse(argc, argv);
}
