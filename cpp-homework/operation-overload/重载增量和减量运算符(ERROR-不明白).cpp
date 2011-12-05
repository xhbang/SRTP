#include <iostream.h>

class T

{   public:

        int x;

        int y;

        T()

        {   x=0;

            y=0;

        }

        void set(int i,int j)

        {   x=i;

            y=j;

        }  

};

void main()
{   T x,arr[5],y;

    x.set(10,20);

    y.set(6,99);

    cout<<"x= "<<x.x<<" "<<x.y<<endl;

    cout<<"y= "<<y.x<<" "<<y.y<<endl;

    for(int i=0;i<=5;i++)

        arr[i].set(i,i*i);

    cout<<"x= "<<x.x<<" "<<x.y<<endl;

    cout<<"y= "<<y.x<<" "<<y.y<<endl;

}