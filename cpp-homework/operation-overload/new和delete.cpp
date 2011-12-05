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

	void * operator new(size_t size){		//ʹ�õ�ʱ���Ƕ���
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
