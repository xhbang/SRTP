//顾客函数文件

#ifndef CONSUMER_cpp
#define  CONSUMER_cpp

#include "consumer.h"
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


//****************************显示顾客界面***********************************
char Consumer::showconsumerLoginMenu()   
{
	system( "cls" );
	system( "color 38" );
	
	cout << endl << " 欢迎来到XXXX书店 ! " << endl
		
		<< "                >>>>>>>>>>>>>>> 欢迎监督书店营业状况 <<<<<<<<<<<<<<< " << endl 
		
		<< "                >> 请选择功能:                                    >> " << endl 
		
		<< "                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl
		
		<< "                >> 1.买书                                         >> " << endl
		
		<< "                >> 2.热门推荐                                     >> " << endl
		
		<< "                >> 3.留言                                         >> " << endl
		
		<< "                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	
	cout<<"请选择 : ";
	char ch;
	cin>>ch;
	return ch;
}

//***********************************买书**************************
void Consumer::buybook()
{
	int i,num,k;
	double price;
	vector< Book > vec1,_Bookshop,_soldbook;
	_Bookshop = setbookshop();
	findbook( vec1 );
	
	if (vec1.size() > 0 )
       cout<<"        1、买书      2、退出   请选择 : ";
	   cin>>i;
	   if ( i == 1)
	   {
		   if (vec1.size() > 1)
		   {	 
			   cout<<"请选择要买的书籍的序号 : ";
			   cin>>k;
			   if( k > 0 && k < vec1.size() )
			   {
				   cout<<"请选择要购买的数量 : ";
				   cin>>num;
				   if(vec1[k-1].get_number() > num )
				   {
					   for(int m1 = 0;m1 < _Bookshop.size(); m1++)
						   if (vec1[k-1].get_serial_number() == _Bookshop[m1].get_serial_number() )
						   {
							   price = vec1[k-1].get_price() * num;
							   _Bookshop[m1].set_number(_Bookshop[m1].get_number() - num );
							   if (_Bookshop[m1].get_number() == 0 )
							   {
								   ofstream outfile2("Leavedwords.txt",ios::app);
								   if ( !outfile2 )
								   throw 1;
								   else
									   outfile2<<left<<__DATE__<<__TIME__
									           <<"书名为 : "<<setw(16)<<_Bookshop[m1].get_bookname()
											   <<"作者是 : "<<setw(16)<<_Bookshop[m1].get_author()
											   <<"已售完 !"<<endl;
								   outfile2.close();
							   }
							   ifstream infile1("Soldbook.txt",ios::in);
							   if(!infile1)
								   throw 1;
							   else
							   {
								   infile1.read( ( char * )&_soldbook, sizeof( vector< Book > ) );
								   for (int m2 = 0; m2 < _soldbook.size(); m2++ )
								   {
									   if(vec1[k-1].get_serial_number() == _soldbook[m2].get_serial_number())
										   _soldbook[m2].set_number( _soldbook[m2].get_number() + num );
								   }
								   if( m2 == _soldbook.size() )
									   _soldbook.push_back( vec1[k-1] );
							   }
							   infile1.close();
							   book_sort(_soldbook,'N');

							   ofstream outfile1("Soldbook.txt");
							   ofstream outfile("Bookshop.txt");
							   if( !outfile || !outfile1 )
								   throw 1;
							   else
							   {
								   for(int n = 0; n < _Bookshop.size(); n++ )
										outfile << left <<setw( 10 ) << _Bookshop[n].get_serial_number() << setw( 16 )
														<<_Bookshop[n].get_bookname()<< setw( 16 ) 
														<< _Bookshop[n].get_author() << setw( 8 ) << _Bookshop[n].get_number() 
														<< setw( 10 ) << _Bookshop[n].get_price() << endl;
								   outfile.close();
								   for ( n = 0; n< _soldbook.size(); n++ )
									   outfile1 << left <<setw( 10 ) << _soldbook[n].get_serial_number() << setw( 16 )
									   <<_soldbook[n].get_bookname()<< setw( 16 ) 
									   << _soldbook[n].get_author() << setw( 8 ) << _soldbook[n].get_number() 
														<< setw( 10 ) << _soldbook[n].get_price() << endl;
								   outfile.close();

							   }
							   cout<<"交易成功, 你共需要支付"<< price <<"元"<<endl;
							  
						   }
				   }
				   else 
					   throw 2;
			   }
			   else  
				   throw 2;
		   }
	   }
   
}

//************************热门推荐************************
void Consumer::charge()
{
	vector<Book> a;
	ifstream infile("Soldbook.txt",ios::in);
	if (!infile)
		throw 1;
	else
	{
		infile.read( ( char *)&a,sizeof( vector< Book > ) );
		book_sort(  a, 'C');
	}
}

//**********************留言******************************
void Consumer::leave_message()
{
	string str;
	cout<<"请在这里留下您的宝贵意见 !\n ";
	cin>>str;
	ofstream outfile("Leavedwords.txt",ios::app);
	if (!outfile)
		throw 1;
	else
	{
		outfile<< left << __DATE__<<__TIME__<<endl
			   << str << endl;
		cout<<"感谢您对本店的支持 !"<<endl;
	}
}


#endif
