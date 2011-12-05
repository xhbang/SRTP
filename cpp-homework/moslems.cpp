//现在问题：怎么判断中文？

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <wchar.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 2

#define SIZE 50
typedef int Status;
typedef char Element;

typedef struct{
	Element *base;
	int front;
	int rear;
}Queue;

typedef struct{
	Element base[SIZE];
	int ptop;
}Stack;

//Stack操作
Status InitStack(Stack &);
int StackEmpty(Stack);		//返回1为空
Status Push(Stack &,Element);
Status Pop(Stack &,Element &);
//Status DestroyStack(Stack &);

//Queue操作
Status InitQueue(Queue &);
//Status DestroyQueue(Queue &);
//int QueueEmpty(Queue)	;			//返回1为空
Status EnQueue(Queue &,Element);
Status DeQueue(Queue &,Element &);

int Check();		//回文判断，是返回1，不是返回0

//定为全局变量
Stack s;
Queue q;

int main(){
	InitStack(s);
	InitQueue(q);
	int answer;
	char control;
	while(1){
		answer=Check();
		if(1==answer){
			printf("yes!\n");
		}
		else
			printf("wrong,again?\n");

		printf("\nInput 'q' to quit and ENTER run again:\n");
		do{  
			scanf("%c",&control);      
			if(control == 'q' || control == 'Q')
				exit(0);
		}while(control!='\n');
//		system("cls");
	}
	return 0;
}

int Check(){
	char input[SIZE];
	printf("please input the buautiful\n");
	scanf("%s",&input);
	int length=strlen(input);
	int i=0;
	if(length%2 !=0)
		return 0;
	for(;i<length/2;i++)
		Push(s,input[i]);
	for(i=length/2;i<length;i++)
		EnQueue(q,input[i]);
	
	char ch1,ch2;
	while(!StackEmpty(s)){
		Pop(s,ch1);
		DeQueue(q,ch2);
		if(ch1 != ch2)
			return 0;
	}
	return 1;
}

Status InitStack(Stack &s){
	s.ptop=-1;
	return OK;
}

int StackEmpty(Stack s){
	return (s.ptop==-1);
}

Status Push(Stack &s,Element a){
	if(s.ptop==SIZE){
		printf("OVERFLOW");
		return OVERFLOW;
	}
	s.ptop++;
	s.base[s.ptop]=a;
	return OK;
}

Status Pop(Stack &s,Element & a){
	if(StackEmpty(s)){
		printf("UNDERFLOW");
		return OVERFLOW;
	}
	a=s.base[s.ptop];
	s.ptop--;
	return OK;
}


//Queue操作
Status InitQueue(Queue &q){
	q.base=(Element *)malloc(SIZE * sizeof(Element));
	if(!q.base)
		exit(OVERFLOW);
	q.front=q.rear=0;
	return OK;
}


Status EnQueue(Queue &q,Element a){
	if((q.rear+1)%SIZE == q.front)
		return ERROR;
	q.base[q.rear]=a;
	q.rear=(q.rear+1)%SIZE;
	return OK;
}

Status DeQueue(Queue &q,Element &a){
	if(q.front==q.rear)
		return ERROR;
	a=q.base[q.front];
	q.front=(q.front+1)%SIZE;
	return OK;
}


