#include <iostream.h>

class Number

{   protected:

        int val;

    public:

        void setval(int i)

        {   val=i;

        }

        virtual void show()=0;

};

class HexType: public Number

{   public:

        void show()

        {   cout<<hex<<val<<endl;

        }

};

class DecType: public Number

{   public:

        void show()

        { //  cout.clear();
			cout<<dec<<val<<endl;

        }

};

class OctType: public Number

{   public:

        void show()

        {   cout<<oct<<val<<endl;

        }

};

void main()

{  Number *p;
	
	HexType hobj;

    OctType oobj;

    DecType dobj;

    p=&hobj;
	p->setval(100);
	p->show();


	p=&oobj;
	p->setval(100);
	p->show();

	p=&dobj;
	p->setval(100);
	p->show();


/*
	dobj.setval (100);
	dobj.show();

    hobj.setval (100);
	hobj.show();

    oobj.setval (100);
	oobj.show();
*/

}