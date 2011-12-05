#include <iostream.h>

class Base

{       int x;

    public:

        Base(int i)

        {   x=i;

        }

        virtual void show()

        {   cout<<"基类Base的虚函数:show()"<<endl;

            cout<<"x= "<<x<<endl;

        }

};

class Derived1: public Base

{       int y;

    public:

        Derived1(int i,int j):Base(j)

        {   y=i;

        }

        void show()

        {   cout<<"派生类Derived1的函数:show()"<<endl;

            cout<<"y= "<<y<<endl;

        }

};

class Derived2: public Base

{       int z;

    public:

        Derived2(int i,int j):Base(j)

        {   z=i;

        }

        void show()

        {   cout<<"派生类Derived2的函数:show()"<<endl;

            cout<<"z= "<<z<<endl;

        }

};

void main()

{   Base obB(10),*pB;
//	Base obB(10);

    Derived1 ob1(100,20);

    Derived2 ob2(200,30);

   pB=&obB;

    pB->show();

   pB=&ob1;

    pB->show();

    pB=&ob2;

    pB->show();
//what's the difference?

	obB.show();
	ob1.show();
	ob2.show();

}