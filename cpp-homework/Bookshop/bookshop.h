//书店头文件

#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include "book.h"
#include <iostream>
#include <vector>

using namespace std;

//*********************************** 书店类 ****************************************

class Bookshop:public Book
{
private:

	vector< Book >  _bookshop;
public:
	Bookshop();

	char showBookshopLoginMenu();
  
	vector< Book >  setbookshop();
    void findbook (  vector<Book> &vec1 );
	void book_sort( vector< Book > &b,char ch);
	void display( vector<Book> b );
};

#endif
