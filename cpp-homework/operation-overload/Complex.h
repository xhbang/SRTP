#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Complex{
	double rpart;
	double ipart;
	double abs() const;			//here the const is must
	double norm() const;
public:
	Complex(){
		rpart=0.0;
		ipart=0.0;
	}
	Complex(const double & ,const double &);
//系统内定数据类型数据转换为类的对象
	Complex(const double &);
//类对象转换为系统其他类型
//	operator double(const Complex &x );		//wrong,为什么？
	operator double();	//right

	void operator=(const Complex &);

	friend int operator>(const Complex &c1,const Complex &c2);
	friend int operator>=(const Complex &c1,const Complex &c2);
	friend int operator<=(const Complex &c1,const Complex &c2);
	friend int operator<(const Complex &c1,const Complex &c2);
	friend int operator==(const Complex &c1,const Complex &c2);
	friend int operator!=(const Complex &c1,const Complex &c2);

	void show();
};

Complex::operator double(){
	return rpart;
}
/*wrong
1>r:\temp\complex.h(20) : error C2835: user-defined conversion 'Complex::operator double' takes no formal parameters
Complex::operator double(const Complex &x ){
	return x.rpart;
}
*/
Complex::Complex(const double &x){
	rpart=x;
	ipart=0;
}

Complex::Complex(const double &i,const double &j){
	rpart=i;
	ipart=j;
}

void Complex::operator =(const Complex &c){
	rpart=c.rpart;
	ipart=c.ipart;
}


double Complex::abs() const{
	double answer=sqrt(rpart*rpart+ipart*ipart);
	return answer;
}

double Complex::norm() const{
	double answer=rpart*rpart+ipart*ipart;
	return answer;
}

void Complex::show(){
	if(ipart>=0)
		cout<<rpart<<"+"<<ipart<<"i"<<endl;
	else
		cout<<rpart<<"-"<<ipart<<"i"<<endl;
}

int operator==(const Complex &c1,const Complex &c2){  
    return c1.rpart ==c2.rpart &&c1.ipart ==c1.ipart ;
}

int operator!=(const Complex &c1,const Complex &c2){  
    return c1.rpart !=c2.rpart ||c1.ipart !=c1.ipart ;
}

int operator<(const Complex &c1,const Complex &c2){
    return c1.abs()<c2.abs();
}

int operator<=(const Complex &c1,const Complex &c2){
    return c1.abs ()<=c2.abs ();
}

int operator>(const Complex &c1,const Complex &c2){
    return c1.abs ()>c2.abs ();
}

int operator>=(const Complex &c1,const Complex &c2){
    return c1.abs ()>=c2.abs ();
}



