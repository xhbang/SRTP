#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;
char a[22][22];
int x=10,y=10;

void qipan();
bool player(int *n,int *s,int *w,int *e);
void food();
void putout(int score);

int main()
{
	int score=0;              //记录分数
	int n=0,s=0,w=0,e=0;
	bool f=true;
	srand(time(0));
	qipan();                   //画边线
	a[x][y]=1;
	while(f)
	{
		food();                  //生成食物
		f=player(&n,&s,&w,&e);   //玩家操作
		if(a[x][y]=='*')         //吃到食物
			score++;
		a[x][y]=1;              
		putout(score);          
		Sleep(100);
	}
	cout<<endl<<"game over!"<<endl;
	Sleep(1000);
	return 0;
}

bool player(int *n,int *s,int *w,int *e)        //上下左右
{
	char c;
	bool f=true;
	a[x][y]=' ';
	if(kbhit())
	{
		switch(c=getch())
		{
		case '1': *w=1;*n=0,*s=0,*e=0;break;
		case '3': *e=1;*n=0,*s=0,*w=0;break;
		case '2': *s=1;*n=0,*w=0,*e=0;break;
		case '5': *n=1;*w=0,*s=0,*e=0;break;
		}
	}
	if(*n) x--; if(x<1) f=false;
	if(*s) x++; if(x>20) f=false;
	if(*w) y--; if(y<1) f=false;
	if(*e) y++; if(y>20) f=false;
	return f;

}

void food()
{
	int i,j;
	for(i=1;i<21;i++)                
		for(j=1;j<21;j++)
			if(a[i][j]=='*')
				i=100;               //i=100则已有食物
	if(i==21)
	{
		do{
			i=rand()%21+1;
			j=rand()%21+1;
		}
		while(a[i][j]!=' ');
		a[i][j]='*';
	}
}

void qipan()
{
	int i,j;
	for(i=1;i<21;++i)
		for(j=1;j<21;++j)
			a[i][j]=' ';
	for(i=0,j=0;j<22;j++)
		a[i][j]='*';
	for(i=21,j=0;j<22;j++)
		a[i][j]='*';
	for(i=0,j=0;i<22;i++)
		a[i][j]='*';
	for(i=0,j=21;i<22;i++)
		a[i][j]='*';
}

void putout(int score)
{
	int i,j;
	system("cls");
	for(i=0;i<22;i++)
	{
		for(j=0;j<22;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"score:"<<score;
}

