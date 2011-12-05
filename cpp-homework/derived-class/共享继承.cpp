#include <iostream.h>

class A{
	int x;
public:
	A(){
		cout<<"A begin"<<endl;
	};

	~A(){
		cout<<"A end"<<endl;
	}

	void setA(int i){
		x=i;
	}

	void show(){
		cout<<"show A:"<<x<<endl;
	}
};

class B1:virtual public A{
	int x;
public:
	B1(int i){
		cout<<"B1 begin"<<endl;
		x=i;
	}

	~B1(){
		cout<<"B end"<<endl;
	}

	void show(){
//		A.show();
		cout<<"x in B1\t"<<x<<endl;
	}

	void showA(){
		A::show();
	}
};

class B2: public A{
	int x;
public:
	B2(int i){
		cout<<"B2 begin"<<endl;
		x=i;
	}

	~B2(){
		cout<<"B2 end"<<endl;
	}

	void show(){
//		A.show();
		cout<<"x in B2\t"<<x<<endl;
	}

	void showA(){
		A::show();
	}

};

class C:public B1,public B2{
	int x;
public:
	C(int i,int j,int k):B1(i),B2(j){
		x=k;
		cout<<"C begin"<<endl;
	}

	~C(){
		cout<<"C end"<<endl;
	}

	void show(){
		cout<<"x in C\t"<<x<<endl;
	}
};


int main(){
	C c(100,200,300);

	c.show();

	c.B1::show();

	c.B2::show();

	c.A::setA(5);
	c.A::show();


	return 0;
}
