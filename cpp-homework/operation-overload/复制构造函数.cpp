//contain poniter type,the default construct is dangerous

#include <iostream.h>
#include <string.h>

class MyString

{       char *str;

    public:

        MyString()

        {   str=new char('\0');

        }

        ~MyString()

        {   delete []str;

        }

        void Myputs()

        {   cout<<str<<endl;

        }

        void Mygets(char *s)

        {   str=new char[strlen(s)+1];

            strcpy(str,s);

        }

        MyString &operator=(const MyString &s)

        {   if(&s==this)

                return *this;

            delete []str;

            str=new char[strlen(s.str)+1];

            strcpy(str,s.str);

            return *this;

        }

		/*this is very important
		MyString(MyString &other){
			str=new char[strlen(other.str)+1];
			strcpy(str,other.str);
		}
		*/

};

int main(){
	MyString str1;
	str1.Mygets("1231441324");
	str1.Myputs();
//copy construct must be write like this
	MyString str2(str1);

	return 0;
}