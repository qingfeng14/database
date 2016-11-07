//
// Created by dalaoshe on 16-11-7.
//

#ifndef FILESYSTEM_INDEX_UTIL_H
#define FILESYSTEM_INDEX_UTIL_H
namespace IndexType {
    enum {
        cluster = 1,
        bucket = 2,
        id = 3,
        index = 4,
        valid = 5,
        invalid = 6,
    };
};
struct Key{
    char* key;
    Key(char* key) {
        this->key = key;
    }
    void writeback(char* page, int len) {
        for(int i = 0 ; i < len ; ++i) {
            *(page+i) = *(key+i);
        }
    }
    bool equal(Key target, int len) {
        char* t = target.key;
        for(int i = 0 ; i < len ; ++i) {
            char a = *(key+i);
            char b = *(t+i);
            if(a != b) return false;
        }
        return true;
    }
    bool less(Key target, int len) {
        return true;
    }
    bool greater(Key target, int len) {
        return true;
    }
};
/*
 * 指向一条索引记录的起始地址
 */
struct Pointer{
    //页id
    int pid;
    //在该页的偏移(若是rid记录则为sid)
    int offset;
    //pointer为索引行的索引指针地址
    Pointer(char* pointer) {
        unsigned int* p = (unsigned int *)pointer;
        this->pid = *(p);
        this->offset = *(p+1);
    }
    Pointer(int pid, int offset) {
        this->pid = pid;
        this->offset = offset;
    }
    void writeback(char* page) {
        int *p = (int *)page;
        *(p) = pid;
        *(p+1) = offset;
    }
    Pointer(){}
};
#endif //FILESYSTEM_INDEX_UTIL_H