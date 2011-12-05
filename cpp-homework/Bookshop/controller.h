//管理员头文件

#ifndef  CONTROLLER_H
#define  CONTROLLER_H

#include "bookshop.cpp"
#include <iostream>

using namespace std;
//****************************管理员类***************************************
class Controller:public Bookshop {
public:

	Controller () { }
	~Controller () { }

	char showControllerLoginMenu ();
	void enter_password ();
	void changepassword ();
	void read_leaved_words ();
	void clear_message ( string );
	void see_soldbook ();
	void enter_book ();
	void read_enterbook();

private:
	vector<char>  pwd;
	vector<string> vec1;
	string coding1 ;
	string coding2 ;
	string  getpwd( vector<char>  &vec ) ;

};

#endif
