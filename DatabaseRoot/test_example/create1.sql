CREATE DATABASE test1
CREATE DATABASE test2
CREATE DATABASE test3

DROP DATABASE test1
CREATE DATABASE test1

USE test3
SHOW DATABASES;

CREATE TABLE customer( id INT(10) NOT NULL, name char(25) NOT NULL, gender char(1) NOT NULL,PRIMARY KEY(id))
DESC customer
DROP TABLE customer
DESC customer