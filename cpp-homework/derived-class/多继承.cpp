#include <iostream.h>

class Base1

{       int x;

    public:

        Base1(int i)

        {   cout<<"调用类Base1的构造函数"<<endl;

            x=i;

        }

        ~Base1()

        {   cout<<"调用类Base1的析构函数"<<endl;

        }

        void show()

        {   cout<<"x in Base1: "<<x<<endl;

        }

};

class Base2

{       int x;

    public:

        Base2(int i)

        {   cout<<"调用类Base2的构造函数"<<endl;

            x=i;

        }

        ~Base2()

        {   cout<<"调用类Base2的析构函数"<<endl;

        }

        void show()

        {   cout<<"x in Base2: "<<x<<endl;

        }

};

class Derived: public Base2,public Base1

{       int x;

    public:

        Derived(int i,int j,int k):Base1(j),Base2(k)

        {   cout<<"调用类Derived的构造函数"<<endl;

            x=i;

        }

        ~Derived()

        {   cout<<"调用类Derived的析构函数"<<endl;

        }

        void show()

        {   cout<<"x in Derived: "<<x<<endl;

        }

};

int main(){
	Derived d(100,200,300);

	d.Base1::show();
	d.Base2::show();

	return 0;
}
