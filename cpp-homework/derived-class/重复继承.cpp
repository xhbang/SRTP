#include <iostream.h>

class A{
	int x;
public:
	A(int i):x(i){
		cout<<"A begin"<<endl;
	};

	~A(){
		cout<<"A end"<<endl;
	}

	void show(){
		cout<<"show A:"<<x<<endl;
	}
};

class B1:public A{
	int x;
public:
	B1(int i,int j):A(i){
		cout<<"B1 begin"<<endl;
		x=j;
	}

	~B1(){
		cout<<"B end"<<endl;
	}

	void show(){
//		A.show();
		cout<<"x in B1"<<x<<endl;
	}

	void showA(){
		A::show();
	}
};

class B2:public A{
	int x;
public:
	B2(int i,int j):A(i){
		cout<<"B2 begin"<<endl;
		x=j;
	}

	~B2(){
		cout<<"B2 end"<<endl;
	}

	void show(){
//		A.show();
		cout<<"x in B2"<<x<<endl;
	}

	void showA(){
		A::show();
	}

};

class C:public B1,public B2{
	int x;
public:
	C(int i,int j,int k,int p):B1(i,j),B2(j,k){
		x=p;
		cout<<"C begin"<<endl;
	}

	~C(){
		cout<<"C end"<<endl;
	}

	void show(){
		cout<<"x in C"<<x<<endl;
	}
};


int main(){
	C c(100,200,300,400);

	c.show();

	c.B1::show();

	c.B2::show();
//way1,using pointer
	A *p=(A*)(B1 *)&c;
	p->show();

	cout<<endl;
//way2,::
	c.B1::showA();
	c.B2::showA();

	return 0;
}
