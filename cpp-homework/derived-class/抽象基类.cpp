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

        {   cout<<val<<endl;

        }

};

class OctType: public Number

{   public:

        void show()

        {   cout<<oct<<val<<endl;

        }

};

void main()

{   HexType hobj;

    OctType oobj;

    DecType dobj;

    dobj.setval (100);

    hobj.setval (100);

    oobj.setval (100);

    dobj.show ();

    hobj.show ();

    oobj.show ();

}
