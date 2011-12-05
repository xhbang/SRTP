//顾客头文件

#ifndef  CONSUMER
#define  CONSUMER

#include "bookshop.cpp"
#include <iostream>

using namespace std;
// *************************顾客类*************************
class Consumer:public Bookshop {
public:
	char showconsumerLoginMenu();
	void buybook();
	void leave_message();
	void charge();//热门推荐
};

#endif
