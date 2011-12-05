#include <iostream>

#include "C.h"

#include <math.h>

#include <stdlib.h>

using namespace std;

double complex::abs ()const

{   double result=sqrt(rpart*rpart+ipart*ipart);

    return result;

}

double complex::norm ()const

{   double result=rpart*rpart+ipart*ipart;

    return result;

}

complex::complex()

{   rpart=0;

    ipart=0;

}

complex::complex(const complex &c)

{   rpart=c.rpart;

    ipart=c.ipart;

}

complex::complex(const double &r,const double &i)

{   rpart=r;

    ipart=i;

}

complex::complex(const double &r)

{   rpart=r;

    ipart=0;

}

void complex::operator =(const complex &r)

{   rpart=r.rpart ;

    ipart=r.ipart ;

}

complex complex::operator - ()

{   complex result;

    result.rpart = -rpart;

    result.ipart = -ipart;

    return result;

}

complex operator+(const complex &c1,const complex &c2)

{   complex result;

    result.rpart =c1.rpart +c2.rpart ;

    result.ipart =c1.ipart +c2.ipart ;

    return result;

}

complex operator-(const complex &c1,const complex &c2)

{   complex result;

    result.rpart =c1.rpart -c2.rpart ;

    result.ipart =c1.ipart -c2.ipart ;

    return result;

}

complex operator*(const complex &c1,const complex &c2)

{   complex result;

    result.rpart =(c1.rpart *c2.rpart )-(c1.ipart *c2.ipart );

    result.ipart =(c1.rpart *c2.rpart )+(c1.ipart *c2.ipart );

    return result;

}

complex operator/(const complex &c1,const complex &c2)

{   complex result;

    double den;

    den=c2.norm();

    if(den!=0.0)

    {   result.rpart =((c1.rpart *c2.rpart )+(c1.ipart *c2.ipart ))/den;

        result.ipart =((c1.ipart *c2.rpart )-(c1.rpart *c2.ipart ))/den;

    }

    else

    {   cout<<"Dive bu 0 "<<endl;

        exit(1);

    }

    return result;

}

complex complex::operator +=(const complex &c)

{   rpart+=c.rpart ;

    ipart+=c.ipart ;

    return *this;

}

complex complex::operator -=(const complex &c)

{   rpart-=c.rpart ;

    ipart-=c.ipart ;

    return *this;

}

complex complex::operator *= (const complex &c)

{   double oldRpart=rpart;

    rpart=(rpart*c.rpart) -(ipart*c.ipart );

    ipart=(oldRpart*c.ipart )+(ipart*c.rpart );

    return *this;

}

complex complex::operator /= (const complex &c)

{   double den=c.norm ();

    if(den!=0.0)

    {   double oldRpart=rpart;

        rpart=(rpart*c.rpart +ipart*c.ipart )/den;

        ipart=(ipart*c.rpart -oldRpart*c.ipart )/den;

    }

    else

    {   cout<<"Dive by 0 "<<endl;

        exit(1);

    }

    return *this;

}

int operator==(const complex &c1,const complex &c2)

{  

    return c1.rpart ==c2.rpart &&c1.ipart ==c1.ipart ;

}

int operator!=(const complex &c1,const complex &c2)

{  

    return c1.rpart !=c2.rpart ||c1.ipart !=c1.ipart ;

}

int operator<(const complex &c1,const complex &c2)

{

    return c1.abs ()<c2.abs ();

}

int operator<=(const complex &c1,const complex &c2)

{

    return c1.abs ()<=c2.abs ();

}

int operator>(const complex &c1,const complex &c2)

{

    return c1.abs ()>c2.abs ();

}

int operator>=(const complex &c1,const complex &c2)

{

    return c1.abs ()>=c2.abs ();

}

void main()

{   complex c1(10,3),c2(15,32),c3;

    c3=(c1+c2);

    c3.show ();

    (c1-c2).show();

}