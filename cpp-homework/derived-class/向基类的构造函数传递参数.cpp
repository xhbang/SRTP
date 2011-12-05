#include <iostream>

using namespace std;

class A{
private:
	int a;
public:
	A(int x):a(x)	{};
	void showA(){
		cout<<"A"<<a<<endl;
	}
};

class B:public A{
	int a,b;
public:
	B(int x,int y):A(x),a(x+y),b(x-y)	{};
	void showB(){
		cout<<"B"<<a<<"&"<<b<<endl;
	}
};
int main(){
	A	a(1);
	a.showA();
	B	b(6,5);
	b.showB();
	b.showA();

	return 0;
}
