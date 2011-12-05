#include <iostream>
using namespace std;

class T{
	int *t;
public:
	T(int size){
		t=new int[size];
	}
	//虚基类
	virtual ~T(){
		cout<<"destory T"<<endl;
		delete [ ]t;
	}
};

class T1:public T{
	int *t1;
public:
	T1(int size1,int size2):T(size2){
		t1=new int[size1];
	}
	~T1(){
		cout<<"destory T1"<<endl;
		delete [ ]t1;
	}
};

int main(){
//	T1 t1(20,30);
	T *p=new T1(20,30);		//T1 destory lost
	delete p;
	return 0;
}
