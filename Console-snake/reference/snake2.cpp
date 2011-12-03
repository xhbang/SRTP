#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;
struct snack
{
     int x;
     int y;
     snack *front;
     snack *next;
};
bool f=true;
char a[22][22];
int x1=10,y1=10;
snack *head;
void begin();
snack *body();
snack *player(int *n,int *s,int *w,int *e,snack *end,int score);
void food();
void putout(int score,snack *head);

int main()
{
     int score=0;
     int n=0,s=0,w=0,e=0;
     snack *end=body();
     system("color b");
     srand(time(0));
     begin();
     putout(score,head);
     while(f)
     {
         food();
         end=player(&n,&s,&w,&e,end,score);
         if(a[x1][y1]=='*')
             score++;
         putout(score,head);
         Sleep(200);
     }
     cout<<endl<<"game over!"<<endl;
     return 0;
}
snack *body()
{
     snack *end,*p1,*p2;
     head=new snack;
     p1=new snack;
     p2=new snack;
     end=p2;
     head->front=0;head->next=p1;    
     head->x=x1;head->y=y1;
     p1->front=head;p1->next=p2;    
     p1->x=x1;p1->y=y1+1;
     p2->front=p1;p2->next=0;    
     p2->x=x1;p2->y=y1+2;
     return end;
}
    

snack *player(int *n,int *s,int *w,int *e,snack *end,int score)
{
     char c;
     snack *p3=end,*p;
     if(kbhit())
     {
         switch(c=getch())
         {
         case 0x4B: *w=1;*n=0,*s=0,*e=0;break;
         case 0x4d: *e=1;*n=0,*s=0,*w=0;break;
         case 0x50: *s=1;*n=0,*w=0,*e=0;break;
         case 0x48: *n=1;*w=0,*s=0,*e=0;break;
		 }
	 }
	 if(*n) x1--; if(x1<1) f=false;
	 if(*s) x1++; if(x1>20) f=false;
	 if(*w) y1--; if(y1<1) f=false;
	 if(*e) y1++; if(y1>20) f=false;
	 if(a[x1][y1]==1&&score!=0) f=false;

	 if(a[x1][y1]=='*')
	 {
		 p3=new snack;
		 end->next=p3;
		 p3->x=end->x;
		 p3->y=end->y;
		 p3->front=end;
		 p3->next=0;
	 }
	 for(p=end;p->front!=0;p=p->front)
	 {
		 p->x=p->front->x;
		 p->y=p->front->y;
	 }
	 head->x=x1;head->y=y1;
	 end=p3;
	 return end;
}

void food()
{
	int i,j;
	for(i=1;i<21;i++)
		for(j=1;j<21;j++)
			if(a[i][j]=='*')
				i=100;
	if(i==21)
	{
		do{
			i=rand()%20+1;
			j=rand()%20+1;
		}
		while(a[i][j]!=' ');
		a[i][j]='*';
	}
}


void putout(int score,snack *head)
{
	int i,j;
	snack *p=head;
	system("cls");
	for(i=1;i<21;++i)
		for(j=1;j<21;++j)
			if(a[i][j]!='*')
				a[i][j]=' ';
	while(p!=0)
	{
		a[p->x][p->y]=1;
		p=p->next;
	}
	for(i=0;i<22;i++)
	{
		for(j=0;j<22;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"score:"<<score;
}
void begin()
{
	char c;
	int i,j;
	do{
		system("cls");
		cout<<"                                     贪吃蛇游戏\n";
		cout<<"                                                                        浩子制作\n\n\n";
		cout<<"操作说明：5，2，1，3为上下左右\t\t输入回车键开始游戏";
	}
	while(c=getchar()!='\n');
	for(i=0,j=0;j<22;j++)
		a[i][j]=2;
	for(i=21,j=0;j<22;j++)
		a[i][j]=2;
	for(i=0,j=0;i<22;i++)
		a[i][j]=2;
	for(i=0,j=21;i<22;i++)
		a[i][j]=2;
}