/* some problem with the code
   help me fix it
   */
#include <iostream.h>
#include <stdlib.h>

template <class T>
class stack{
	private:
		T *b,*p;
		int size;
	public:
		stack(int sz=0):size(sz){
			b=p=new T[size];
		}
		~stack(){
			delete []b;
		}

		int getsize() const{
			return p-b;
		}

		void push(const T&item){
			if (p>=b+size)			//>=
			{
				cout<<"OVERFLOW"<<endl;
				exit(1);
			}
			*p++=item;
		}

		T pop(){
			if(p<b){			//<=
				cout<<"UNDERFLOW"<<endl;
				exit(2);
			}
//			T val=*--p;
			T val=*p;
			p--;
			return val;
		}

};

//for test
int main(){
	stack<char> * S_ch=new stack<char>(26);
	for(int i=97;i<97+26;i++)
		S_ch->push(i);
	while(S_ch->getsize!=0){
		cout<<S_ch->pop()<<endl;
	}

	return 0;
}
