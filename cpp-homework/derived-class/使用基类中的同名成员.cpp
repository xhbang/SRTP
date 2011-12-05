#include <iostream>
using namespace std;
 
class A{
	int i,j;
public:
//此处使用public使之可以访问
	int z;
	A(int x,int y):i(x),j(y),z(0)	{};
	void show(){
		cout<<"A:"<<i<<j<<endl;
		cout<<z<<endl;
	}
};

class B:public A{
public:
	int z;
	B(int x,int y):A(x,y)	{};
	void show(){
		cout<<"Z\t"<<z<<endl;
	}
};

int main(){

	B b(4,5);
	b.A::z=9;
	b.z=99;
	b.A::show();
	b.show();

	return 0;
}
