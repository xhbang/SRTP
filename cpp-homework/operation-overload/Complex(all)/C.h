//complex.h 声明复数类的数据成员和接口
#include <iostream>
using namespace std;
class complex

{   private:

        double rpart;

        double ipart;

        double abs()const;

        double norm()const;

    public:

        complex();

        complex(const complex &c);

        complex(const double &r,const double &i);

        complex(const double &r);

        void operator=(const complex &c);

        complex operator-();

        friend complex operator+(const complex &c1,const complex &c2);

        friend complex operator-(const complex &c1,const complex &c2);

        friend complex operator*(const complex &c1,const complex &c2);

        friend complex operator/(const complex &c1,const complex &c2);

        complex operator+=(const complex &c);

        complex operator-=(const complex &c);

        complex operator*=(const complex &c);

        complex operator/=(const complex &c);

        friend int operator==(const complex &c1,const complex &c2);

        friend int operator!=(const complex &c1,const complex &c2);

        friend int operator<(const complex &c1,const complex &c2);

        friend int operator>(const complex &c1,const complex &c2);

        friend int operator<=(const complex &c1,const complex &c2);

        friend int operator>=(const complex &c1,const complex &c2);

        void show()

        {   if(ipart>=0.0)

                cout<<rpart<<"+"<<ipart<<"i"<<endl;

            else

                cout<<rpart<<ipart<<"i"<<endl;

        }

};