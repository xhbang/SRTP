#include <iostream>
#include "Complex(all).h"
//#include <cstdlib>
//#include <cmath>
#include <stdlib.h>
#include <math.h>
using namespace std;


Complex::Complex(){
	rpart=0.0;
	ipart=0.0;
}

Complex::Complex(const Complex &x){
	rpart=x.rpart;
	ipart=x.ipart;
}

Complex::Complex(const double &x){
	rpart=x;
	ipart=0.0;
}

Complex::Complex(const double &x1, const double &x2){
	rpart=x1;
	ipart=x2;
}
//注意const
double Complex::abs() const{
	double answer=rpart*rpart+ipart*ipart;
	return sqrt(answer);
}

double Complex::norm() const{
	double answer=rpart*rpart+ipart*ipart;
	return answer;
}

void Complex::operator =(const Complex &x){
	rpart=x.rpart;
	ipart=x.ipart;
}

void Complex::show(){
	cout<<rpart<<((ipart>0.0)?"+":"")<<ipart<<"i"<<endl;		//pan attention to ()
}


Complex Complex::operator -(){
	Complex x;
	x.rpart=-rpart;
	x.ipart=-ipart;
	return x;
}

Complex::operator double(){
	return rpart;
}

//这里不用加Complex::
Complex operator+(const Complex& x1,const Complex& x2){
	Complex x;
	x.rpart=x1.rpart+x2.rpart;
	x.ipart=x1.ipart+x2.ipart;
	return x;
}

Complex operator-(const Complex& x1,const Complex& x2){
	Complex x;
	x.rpart=x1.rpart-x2.rpart;
	x.ipart=x1.ipart-x2.ipart;
	return x;
}

Complex operator*(const Complex& x1,const Complex& x2){
	Complex x;
	x.rpart=x1.rpart*x2.rpart-x1.ipart*x2.ipart;
	x.ipart=x1.rpart*x2.rpart-x1.ipart*x2.ipart;
	return x;
}

Complex operator/(const Complex& x1,const Complex& x2){
	Complex x;
	double temp=x2.norm();
	if(temp!=0.0){
		x.rpart=(x1.rpart*x2.rpart+x2.ipart*x1.ipart)/temp;
		x.ipart=(x1.rpart*x2.ipart-x1.ipart*x2.rpart)/temp;
		return x;
	}
	else{
		cout<<"x2 equals zero!"<<endl;
		exit(1);
	}

}

int operator ==(const Complex& x1,const Complex& x2){
	return x1.rpart==x2.rpart && x1.ipart==x2.ipart;
}

int operator !=(const Complex& x1,const Complex &x2){
	return x1.rpart!=x2.rpart || x2.ipart==x1.ipart;
}

int operator >(const Complex& x1,const Complex& x2){
	return x1.norm()>x2.norm();
}

int operator <(const Complex& x1,const Complex& x2){
	return x1.norm()<x2.norm();
}

int operator >=(const Complex& x1,const Complex &x2){
	return x1.norm()>=x2.norm();
}

int operator <=(const Complex& x1,const Complex& x2){
	return x1.norm()<=x2.norm();
}
//返回complex
Complex Complex::operator +=(const Complex &x){
	rpart+=x.rpart;
	ipart+=x.ipart;
	return *this;
}

Complex Complex::operator -=(const Complex &x){
	rpart-=x.rpart;
	ipart-=x.ipart;
	return *this;
}

Complex Complex::operator *=(const Complex &x){
	double oldRpart=rpart;
	rpart=rpart*x.rpart-ipart*x.ipart;
	ipart=oldRpart*x.ipart+ipart*x.rpart;
	return *this;
}

Complex Complex::operator /=(const Complex &x){
	double temp=x.norm();
		if(temp!=0.0){
			double oldRpart=rpart;
			rpart=(rpart*x.rpart+ipart*x.ipart)/temp;
			ipart=(ipart*x.rpart-oldRpart*x.ipart)/temp;
		}
		else{
			cout<<"ERROR"<<endl;
			exit(1);
		}
		return *this;
}




int main(){
	Complex c1(20.34,13.12),c2(42),c3;
	c3=c1+c2;
	c3.show();
	c3=-c3;
	c3.show();

	return 0;
}

