#include "Complex(all).h"

int main(){
	Complex c1(20.34,13.12),c2(42),c3;
	c3=c1+c2;
	c3.show();
	c3=-c3;
	c3.show();

	return 0;
}