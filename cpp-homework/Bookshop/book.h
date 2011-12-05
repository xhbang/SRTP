//书类及其函数  头文件

#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;
//********************************** 书类 ***************************************

class Book
{
private:
	string bookname;
	string author;
	string serial_number ;
	int  number;
	double price;
public:
//―――――――――― 设置数据 ――――――――――――
	void setbook(string serial_number,string bookname,
		string author, int number,double price)
	{
		this->serial_number=serial_number;
		this->bookname=bookname;
		this->author=author;
		this->number=number;
		this->price=price;
	}
	void set_serial_number(string x)
	{
		serial_number = x;
	}
	void set_bookname(string x)
	{
		bookname = x;
	}
	void set_author(string x)
	{
		author = x;
	}
	void set_number(int x)
	{
		number = x;
	}
	void set_price(double x)
	{
		price = x;
	}
//―――――――――― 获取数据 ――――――――――――
	string get_serial_number()
	{
		return serial_number;
	}
	string get_bookname()
	{
		return bookname;
	}
	string get_author()
	{
		return author;
	}
	int get_number()
	{
		return number;
	}
	double get_price()
	{
		return price;
	}
};

#endif
