#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
	double rpart;
	double ipart;
	double abs() const;
	double norm() const;
public:
	Complex();
	Complex(const double &);
	Complex(const double &,const double &);
	Complex(const Complex&);

	void operator=(const Complex&);
	Complex operator -();
	operator double();
	void show();

	friend Complex operator+(const Complex& ,const Complex&);
	friend Complex operator-(const Complex&,const Complex&);
	friend Complex operator*(const Complex&,const Complex&);
	friend Complex operator/(const Complex&,const Complex&);	

	friend int operator==(const Complex&,const Complex&);
	friend int operator!=(const Complex&,const Complex&);
	friend int operator>(const Complex&,const Complex&);
	friend int operator<(const Complex&,const Complex&);
	friend int operator>=(const Complex&,const Complex&);
	friend int operator<=(const Complex&,const Complex&);
//²»ÒªÅª³Éfriend
	Complex operator +=(const Complex &);
	Complex operator -=(const Complex &);
	Complex operator *=(const Complex &);
	Complex operator /=(const Complex &);

};



#endif