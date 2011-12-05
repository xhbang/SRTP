//管理员函数文件

#ifndef COTROLLER_CPP
#define COTROLLER_CPP

#include "controller.h"
#include <iostream>
#include <conio.h> 
#include <sstream>
#include <iomanip>
#include <fstream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//***************************查看已进的书籍************************************
void Controller::read_enterbook()
{
	
	string mon;
	string day;
	string year;
	string time;
	string bookname;
	string author;
	string serial_number ;
	int  number;
	double price;
	ifstream infile ("enteredbook.txt",ios::in);
	if (!infile)
		throw 1; 
	else
		while (infile>>mon)
		{
			infile >> day >> year >> time >> serial_number >> bookname >> author >> number >> price;
			cout << left << setw(3) << mon << setw(3) << day << setw(5) << year << setw(10) << time
   		  		 << setw(10) << serial_number << setw(16) << bookname << setw(16) << author
				 << setw(6) << number << setw(6) << price << endl << endl;
		}
		
}

//******************************进书**************************************
void Controller::enter_book()
{
	vector< Book > a;
    Book book;
	a = setbookshop();
	string bookname;
	string author;
	string serial_number ;
	int  number;
	double price;
	ofstream enter("enterbook.txt",ios::app);
	if (!enter)
	    throw 1; 
	else
	{
b:	cout << "请输入编号 : " ;
    cin >>serial_number  ;

	cout << "请输入书名 : " ;
	cin >> bookname ;

	cout << "请输入作者姓名 : " ;
	cin >> author;

	cout << "请输入数量 : " ;
	cin>>number;

	cout << "请输入单价 : ";
	cin >> price;
   
	for( int i = 0; i <a.size() ; i++ )
		if( serial_number == a[i].get_serial_number() )
			if( bookname != a[i].get_bookname() || author !=a[i].get_author() || price != a[i].get_price() )
				throw 2;
			else
			{
				a[i].set_number(a[i].get_number() + number) ;
				enter <<left<<setw(12)<<__DATE__
					  <<setw(12)<<__TIME__<<setw(10)<<serial_number
					  << setw( 16 ) <<bookname << setw( 16 ) << author
			          << setw( 8 ) <<number << setw( 10 ) << price << endl;
				break;
			}
	if( i >= a.size() )
	{
		book.set_serial_number(serial_number);
		book.set_bookname(bookname);
		book.set_author(author);
		book.set_number(number);
		book.set_price(price);
		a.push_back(book);
		enter <<left<<setw(12)<<__DATE__
		  	  <<setw(12)<<__TIME__<<setw(10)<<serial_number
			  << setw( 16 ) <<bookname << setw( 16 ) << author
			  << setw( 8 ) <<number << setw( 10 ) << price << endl;
	}
	
	cout << "继续请按 y ，否则请按其他任意键。请选择 : ";
	char ch;
	cin >> ch;

	if( ch == 'y' )
		goto b;
	else
	{
		ofstream outfile( "Bookshop.txt" );

		if( !outfile )
			throw 1;
		else
		{
			for (i=0;i<a.size();i++)
			{
				outfile << left <<setw( 10 ) << a[i].get_serial_number() << setw( 16 ) << a[i].get_bookname()
						<< setw( 16 ) << a[i].get_author() << setw( 8 ) << a[i].get_number() 
						<< setw( 10 ) << a[i].get_price() << endl;
			}
		}

		outfile.close();

	}
	enter.close();
	}
}

//***************************查看已销售的书******************************************
void Controller::see_soldbook()
{      
	vector<Book> a;
	ifstream infile( "Soldbook.txt" ,  ios::in );

	if( !infile )
		throw 1;
	else {
		infile.read( (char *)&a,sizeof( vector<Book> ) );
		book_sort(  a, 'M');
	   
	}

	infile.close();

    cout << "需要删除销售记录请按 y , 否则请按其他任意键 :";
	char ch;
	cin >> ch;
	if( ch == 'y' )
		clear_message( "soldbook.txt" );
}

//*****************************输入密码 ，正确后才能进入管理员界面******************************************
 
void Controller::enter_password()    
{
	string password;
	string s1;
	int i = 0,m = 0;

	ifstream infile( "Coding.txt" );

    if( !infile )
	{
		throw 1;
        infile.close();
	}
	else{
	  infile >> s1; 
	  infile.close();
	  cout << "\n                 请输入密码 : ";

	  password=getpwd(   pwd   ); 
	  
	  if( s1 == password )
			showControllerLoginMenu();
	  else
	  {
		  while( 1 )
		  {
			  cout<<"\n                 请输入密码 : ";
			  password=getpwd(   pwd   ); 
			  
			  if(s1==password)
			  {
				   showControllerLoginMenu();
				   break;
			  }
			  else{
				  cout << "登录失败 ! (输入 y 表示重新登录，其他任意键表示不登录.) \n "
					   << "     请选择 : ";
				  char m;
				  cin >> m;

				  if(m == 'y')
					  pwd.clear();
				  else
					  goto f;
			  }
		  }
	 }
	
f:    cout << endl;
	}
}


//************************管理员界面********************************
char Controller::showControllerLoginMenu()   
{
	system( "cls" );
	system( "color 47" );

	cout << endl << " 尊敬的管理员,你好! " << endl

		<< "                >>>>>>>>>>>>>>> 欢迎监督书店营业状况 <<<<<<<<<<<<<<< " << endl 

		<< "                >> 请选择功能:                                    >> " << endl 

		<< "                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl

		<< "                >> 1.找书                                         >> " << endl
		
		<< "                >> 2.查看销售业绩                                 >> " << endl
		
		<< "                >> 3.买进书籍                                     >> " << endl

		<< "                >> 4.查看已卖出的书籍                             >> " << endl

		<< "                >> 5.查看已售完的书籍                             >> " << endl

		<< "                >> 6.修改密码                                     >> " << endl

		<< "                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;

	cout<<"请选择 : ";
	char ch;
	cin>>ch;
	return ch;
}

//********************查看留言****************************************                                                                                                                                                                                                                                                  
void Controller::read_leaved_words(){   
	string s1=0;
	ifstream infile( "Leavedwords.txt" );

	if( !infile )
		throw 1;
	else
	{
		while( infile >> s1 )
		{
			cout << s1 << endl;
		}

		cout << "是否清除留言 ? "
			 << "  (输入 y 表示清除留言 , 其他任意键表示不清除留言 .)\n"
			 << "请选择 : ";
		char i;
		cin >> i;

		if(  i == 'y'  )
		      clear_message(  "leavewords.txt"  );
	}

}


//*******************************修改密码****************************************	   
void Controller::changepassword()
{      
b:	  cout <<  "请输入新密码 : ";
      coding1 =  getpwd(   pwd   ); 
	  pwd.clear();
	  cout << "请确认新密码 : ";
	  coding2 = getpwd( pwd );
	  pwd.clear();

	  if( coding1 == coding2 )
	  {
		  ofstream outfile( "Coding.txt" );
		  if( !outfile )
			  throw 1;
		  else{
				outfile << coding1 << endl;
				cout << "修改成功 !\n";	
		  }

		  outfile.close();

	  }
	  else{
		   cout << "输入错误 , 请确认后重新输入 !\n";
		   goto  b;
	  }

 }
      
//****************************密码设置方式******************************************
string  Controller::getpwd( vector<char>  &vec )    
{   
  char   c = 0 ;   
  while( ( c = _getch() )!= '\r' )          
  {                                                        //_getch()   接收一个字符     且不在屏幕上显示     
	  if(c   ==   0x08)                       //0x08   为退格符     判断是不是输入的退格符       
	  {   
		  if( !vec.empty() )   
			 {   
			  cout << char(0x08) <<'   '<<char(0x08);       //若是退格符     进行退格     退格符不进行抹除     所以要输出一个空格   
			  vec.pop_back();   
			}     
		  continue;     
	  }   
	  else   
		 vec.push_back(   c   );   
            
	  cout << '*' ;   
  }   
	  cout << endl;   
    
      char* cpwd = new char[ vec.size() + 1 ];   
	  char*  p = cpwd;     
    
	  for ( int i = 0 ; i < vec.size() ; i++ , cpwd++ )   
			 *cpwd = vec[i]   ;
	  
	  *cpwd = '\0' ;   
      string  spwd(p);   
    
	  return  spwd;   
 }

#endif
