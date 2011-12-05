//重载赋值运算符必须使用成员函数，不能使用友员函数或非友员外部函数。

#include <iostream.h>
#include <string.h>

class Mystr{
	char *str;
public:
	Mystr(){
		str= new char('\0');
	}
	~Mystr(){
		delete [ ]str;
	}
	void showstr(){
		cout<<str<<endl;
	}
	void reset(char *s){
//		delete [ ]str;
		str=new char[strlen(s)+1];
		strcpy(str,s);
	}

	Mystr& operator=(const Mystr &other){		//must have a &
//		if(str==other.str)
		if(&other==this)
			return *this;
		delete [ ]str;
		str= new char[strlen(other.str)+1];
		strcpy(str,other.str);

		return *this;
	}





};

void main(){
	Mystr str1,str2;
	str1.reset("123455");
	str2.reset("657568");
	str1.showstr();
	str2.showstr();

	str2=str1;
	str2.showstr();

}