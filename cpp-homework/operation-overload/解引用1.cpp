//make it equal "."

#include <iostream>
using namespace std;

class T{
public:
	int x;		//make it public so we can visit it
	T * operator ->(){
		return this;
	}
	void show(){
		cout<<x<<endl;
	}
};

int main(){
	T ob;
	ob.x=50;
	ob.show();
	ob->x=100;
	ob.show();

	return 0;
}