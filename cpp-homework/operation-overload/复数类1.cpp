#include <iostream.h>

class Complex{
	double rpart;
	double ipart;
public:
	Complex(){
		rpart=0.0;
		ipart=0.0;
	}

	Complex(double i,double j){
		rpart=i;
		ipart=j;
	}

	void show(){
		if(ipart>0.0)
			cout<<rpart<<"+"<<ipart<<"i"<<endl;
		else
			cout<<rpart<<"-"<<ipart<<"i"<<endl;
	}
/*
	Complex& operator+(double x){
		rpart=rpart+x;
		return *this;		//
	}
*/
	friend Complex operator+(Complex& ,double );
//½»»»ÂÉ
	friend Complex operator+(double ,Complex &);
};
//no need: friend Complex::operator
Complex operator+(Complex &c,double x){
	c.rpart+=x;
	return c;
}

Complex operator+(double x,Complex &c){
	c.rpart=x+c.rpart;
//	c.rpart+=x;					//different answer
//	c.rpart=c.rpart+x;
	return c;
}

int main(){
	Complex num(5.9,6.3);
	num.show();
	num=num+(-7.9);
//wrong
//	num=num-7.9;
	num.show();
	num=7.9+num;
	num.show();
	return 0;
}