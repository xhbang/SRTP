#define N 5
#include <iostream>
#include <string.h>
using namespace std;

class T{
	int data;
	char name[20];
public:
	T(){
		data=0;
		strcpy(name,"");
	}
	void show(){
		cout<<data<<":"<<name<<endl;
	}
	T operator () (int n,char *s){
		data=n;
		strcpy(name,s);
		return *this;
	}
};

int main(){
	T t[N];
	int num;
	char n[20];
	for(int i=0;i<N;i++){
		cin>>num;
		cout<<"next"<<endl;
		cin>>n;
		t[i](num,n);
	}
	for(i=0;i<N;i++)
		t[i].show();

	return 0;
}