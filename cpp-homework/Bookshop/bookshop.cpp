// 书店函数文件 

#ifndef  BOOKSHOP_CPP
#define BOOKSHOP_CPP

#include "bookshop.h"
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

//********************************* 构造函数 ********************************************

Bookshop::Bookshop()
{
	ifstream infile ( "Bookshop.txt" );
	if ( !infile)
		throw 1;
	else 
	{
		infile.read( ( char * )&_bookshop,sizeof( vector< Book > ) );
	}
	infile.close();
}


//******************************* 提取文件内容到内存 ************************************************

vector < Book >  Bookshop::setbookshop()
 {
 	 _bookshop.clear();

	 ifstream infile ("Bookshop.txt");
	 if (!infile)
		 throw 1;
	 else
	 {
		infile.read( ( char * )&_bookshop,sizeof( vector<Book> ) );
	 }
	 infile.close();
	 return _bookshop;

 }

//***************************** 打印  ***********************************************

void Bookshop::display( vector<Book> b )
{
	
		size_t m = 0; 
		for(; m < b.size(); m++)
			cout << left <<setw( 10 ) <<b[m].get_serial_number() << setw( 16 ) <<b[m].get_bookname() 
			     << setw( 16 ) <<b[m].get_author() << setw( 8 ) <<b[m].get_number()
				 << setw( 10 ) << b[m].get_price() << endl;
}

//************************************ 找书 *********************************************

void Bookshop::findbook( vector<Book> &vec1 )
{
	vec1.clear();
	vector<Book> b;
    int i = 0, n = 0, m = 0;
    string bookname;
	string author;
	string serial_number ;
	b = setbookshop();                             //将文件内容存放到容器中

	cout <<"1、按书名查找    2、按作者姓名查找   "
		 <<"请选择 : ";
	cin >> i;
	switch(i)
	{  
		case 1:     cout <<"请输入书名 : ";
            		cin>>bookname;

					for((size_t)m = 0; m < b.size(); m++ )
						if(b[m].get_bookname() == bookname)
						{
						   n++;
						   vec1.push_back(b[m]);
						}

					if( n == 0 )
						cout << "对不起 ! 你要找的信息不存在 。" <<endl;
					else
						cout << " 共找到 " << n <<" 个结果 !\n";

                    break;

		case 2:     cout << "请输入作者姓名 : ";
					cin >> author;

					for(m = 0; m < b.size(); m++ )
						if(b[m].get_author() == author)
						{
							n++;
				            vec1.push_back(b[m]);
						}

					if( n == 0 )
						cout << "对不起 ! 你要找的信息不存在 。" <<endl;
					else
						cout << " 共找到 " << n <<" 个结果 !\n";
					
					
					break;

		default:   throw 2;
	}
	if( vec1.size() != 0 )
       for ( m = 0; m < vec1.size(); m++ )
		   cout << left << setw(3) << m + 1 << setw(10) << vec1[m].get_serial_number()
			    << setw(16) << vec1[m].get_bookname() << setw(16)
			    << vec1[m].get_author() << setw(5) << vec1[m].get_number()
				<< setw(8) << vec1[m].get_price() << endl;
}
//*************************** 书店进入界面 *****************************

char  Bookshop::showBookshopLoginMenu()   
{
	system( "cls" );
	system( "color 56" );

	cout << endl << "                               XXXX书店欢迎您 ! " << endl<<endl
		<< "                >>>>>>>>>>>>>>> 欢迎监督书店营业状况 <<<<<<<<<<<<<<< " << endl 
		<< "                >> 请选择功能:                                    >> " << endl 
		<< "                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl
		<< "                >> 1.顾客登录                                     >> " << endl 
		<< "                >> 2.管理员登录                                   >> " << endl 
		<< "                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;

	cout<<"请选择 : ";
	char ch;
	cin>>ch;
	return ch;
}
//***************************** 排序输出 **********************************************

void Bookshop::book_sort( vector< Book > &b,char ch)
{
	int i, n;
	Book p;
	for ( i = 0; i < b.size(); i++ )
		for(n = 0; n < (b.size() - i - 1 ); n++ )
		{
			if ( b[n].get_number()  <  b[n+1].get_number() )
			{
				p = b[n];
				b[n] = b[n+1]; 
				b[n+1]=p;
			}
		}
		switch (ch)       //M 代表管理员全部输出，   C 代表顾客输出5项 ，  N 代表不做任何事。
		{
		case 'M': 
			for (  i=0;i<b.size();i++)
				cout<<left<<setw(10)<<b[i].get_serial_number()
				    <<setw(16)<<b[i].get_bookname()<<setw(16)
					<<b[i].get_author()<<setw(5)<<b[i].get_number()
					<<setw(8)<<b[i].get_price()<<endl;
			break;

		case 'C':
		   for ( n = 0;n < 5 ; n++ )
				cout<<left<<setw(10)<<b[n].get_serial_number()
					<<setw(16)<<b[n].get_bookname()<<setw(16)
					<<b[n].get_author()<<setw(5)<<b[n].get_number()
				    <<setw(8)<<b[n].get_price()<<endl;
		   break;

		case 'N':
			break;

		default:
			throw 2;

		}
}

#endif

