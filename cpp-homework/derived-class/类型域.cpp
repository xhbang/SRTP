/*
通过以下几个步骤可以到达在类定义中增加类型域的目的：
◆ 定义一个枚举类型，用该枚举类型来表示应用程序所涉及到的各种对象类型。
◆ 在派生类的基类中增加一个类型说明数据成员(类型域)，该数据成员的数据类型为表示对象类型的枚举类型。
类型说明数据成员应该被声明为公有的，以便派生类能够自动继承，并且在外部函数中能够访问。
◆ 修改基类和派生类的构造函数使之能够在创建基类或派生类对象时为所创建对象的类型说明数据成员赋予表示对象类型的枚举值。
◆ 为每个对象的类型说明数据成员赋值的操作也可以不通过类的构造函数进行，而使用类的成员函数进行设置。
*/

#include <iostream>
using namespace std;

typedef enum type{A,B} type;
//enum type{A,B};

class T{
	int x;
public:
	//为了方便，放在PUBLIC
	type mtype;
	void setT(int i){
		x=i;
	}
	int showT(){
		return x;
	}
};

class T1:public T{
	int y;
public:
	void setT1(int i){
		y=i;
	}
	int showT1(){
		return y;
	}
};

int main(){
	T1 t1[5];
	T *p[5];
	
	for(int i=0;i<5;i++)
		p[i]=&t1[i];
	int type;
	cout<<"choose type:1 for A,2 for B"<<endl;
	for(i=0;i<5;i++){
		cin>>type;
		switch(type){
			case 1:
				p[i]->mtype=A;
				p[i]->setT(i+1);
				break;

			case 2:
//				p[i]->mtype=B;
//				p[i]->setT(i+1);
				((T1*)p[i])->mtype=B;
				((T1*)p[i])->setT1(i+1);
		}
	}
/*
	for(i=0;i<5;i++){
		cout<<p[i]->showT()<<"\t"<<p[i]->mtype<<endl;
	}
*/
	for(i=0;i<5;i++){
		switch(p[i]->mtype){
		case 0:
			cout<<p[i]->showT()<<"\ttype A"<<endl;
			break;
		case 1:
			cout<<((T1*)p[i])->showT1()<<"\ttype B"<<endl;
		}
	}
	return 0;
}
