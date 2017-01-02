CREATE DATABASE orderDB1;

USE orderDB1;

CREATE TABLE publisher (
  id int(10) NOT NULL,
  name varchar(100) NOT NULL,
  state varchar(2),
  PRIMARY KEY  (id)
);

CREATE TABLE book (
  id int(10) NOT NULL,
  title varchar(100) NOT NULL,
  authors varchar(200),
  publisher_id int(10) NOT NULL,
  copies int(10)
  );

CREATE TABLE customer (
  id int(10) NOT NULL,
  name varchar(25) NOT NULL,
  gender varchar(1)
  );

CREATE TABLE orders (
  customer_id int(10) NOT NULL,
  book_id int(10) NOT NULL,
  quantity int(10) NOT NULL
);
