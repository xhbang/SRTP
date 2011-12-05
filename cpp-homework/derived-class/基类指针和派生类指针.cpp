#include <iostream>

using namespace std;

class T{
	int x;
public:
	void setT(int i){
		x=i;
	}
	int getT(){
		return x;
	}
};

//must be public,or illegal
class  T1:public T{
	int y;
public:
	void setT1(int i){
		y=i;
	}
	int getT1(){
		return y;
	}
};

int main(){
	T1 t1;
	T *t=&t1;	

	t->setT(1);
	cout<<t->getT()<<endl;

//	t->setT1(2);
//	cout<<t->getT1()<<endl;

	//remember the two (()) because -> has a higher prior than () 
	((T1*)t)->setT1(3);
	cout<<((T1*)t)->getT1()<<endl;

	return 0;
}

/*我还没有模拟指针移动时的情形
（2）该指针移动的数据单位是基类对象所占的存储单元长度而不是派生类对象所占的存储单元长度。
例如：对指向派生类的基类指针执行一次自增(++)运算,它将会指向下一个基类型的对象,而不是指向下一个派生类型的对象。
*/
