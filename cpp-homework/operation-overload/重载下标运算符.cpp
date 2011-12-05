//下标运算符重载函数只能是非静态成员函数，不能是友员函数或者一般外部函数。

#include <iostream>
using namespace std;

typedef int T;
class Array{
	T *p;
	int size;
public:
	Array(T *a)	{p=a;}
	Array(T *a,int i){
		p=a;
		size=i;
	}
	T& operator [ ](int i){			//必须要有T&
		if(i<0 || i>size){
			cout<<"FLOW ERROR"<<endl;
			exit(1);
		}
		return p[i];
	}

};

int main(){
	int a[4];
	Array arr(a,4);

	for(int i=0;i<4;i++)
		cin>>arr[i];

	for(i=0;i<4;i++)
        cout<<"arr["<<i<<"]="<<arr[i]<<endl;

	cout<<arr[5]<<endl;

	return 0;
}

/*SAMPLE
typedef int T;

#define N 5

#include <stdlib.h>

#include <iostream.h>

class ArrType

{       T *a;

public:

        ArrType(T *x)

        {   a=x;

        }

        T &operator[](int i)

        {   if(i<0||i>=N)

            {   cout<<"Boundary Error"<<endl;

                exit（1）;

            }

            return a[i];

   }

};

void main()

{   T a[N];

    ArrType arr(a);

    for(int i=0;i<N;i++)

        cin>>arr[i];

    for(i=0;i<N;i++)

        cout<<"arr["<<i<<"]="<<arr[i]<<endl;

//  arr[10]=1000;             //错误

//  cout<<arr[5]<<endl;       //错误

}
*/