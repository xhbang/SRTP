typedef int T;

#include <iostream.h>

#include <stdlib.h>

class Array

{       T *p;

        T *arr;

        int size;

    public:

        Array(T *p1,T *a,int sz);

        Array(T *p1);

        Array operator++();		//++a

        Array operator++(int);		//a++

        Array operator--();

        Array operator--(int);

        T &operator*();

};

Array::Array(T *p1,T*a,int sz)		//a是数组位置，p1是数组中位置

{   p=p1;

    arr=a;

    size=sz;

}

Array::Array(T *p1)

{   p=arr=p1;

    size=1;

}

Array Array::operator ++ ()

{   if(p-arr>=size)

    {   cout<<"Overflow"<<endl;

        exit(1);

    }

    ++p;

    return *this;

}

Array Array::operator ++ (int)

{   if(p-arr>=size)

    {   cout<<"Overflow"<<endl;

        exit(1);

    }

    Array temp=*this;

    p++;

    return temp;

}

Array Array::operator -- ()

{   if(p<=arr)

    {   cout<<"Underflow"<<endl;

        exit(1);

    }

    --p;

    return *this;

}

Array Array::operator -- (int)

{   if(p<=arr)

    {   cout<<"Underflow"<<endl;

        exit(1);

    }

    Array temp=*this;

    p--;

    return temp;

}

void main()

{   T a[5];

    Array arr(&a[0],a,4);

    arr++;
	
	++arr;

//  Array arr1(a+5,a,5);

//  arr1++;

}