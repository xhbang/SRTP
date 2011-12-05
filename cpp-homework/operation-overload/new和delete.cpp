#include <iostream>
#include <stdlib.h>
using namespace std;

class T{
private:
	int x;
	int y;
public:
	T(int i,int j):x(i),y(j){
		cout<<"Construct"<<endl;
	}

	~T(){
		cout<<"Destory"<<endl;
	}

	friend ostream& operator<<(ostream &out,const T& t){
		out<<t.x<<"\t"<<t.y<<endl;
		return out;
	}

	void * operator new(size_t size){		//使用的时候是多少
		void * p;
		p=malloc(size);
		return p;
	}

	void operator delete(void * p){
		delete p;
	}


};

int main(){
	T *p;
	p= new T(20,30);
	cout<<*p;
	delete p;


	return 0;
}
