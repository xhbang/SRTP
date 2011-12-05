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
		delete [ ]str;
		str=new char[strlen(s)+1];
		strcpy(str,s);
	}
};

int main(){
	Mystr str1,str2;
	str1.reset("32423424");
	str2.reset("233423552");

	str1.showstr();
	str2.showstr();

//	str2=str1;		//cause a problem here

	return 0;
}
