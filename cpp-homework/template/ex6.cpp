//静态为二分查找
//动态为二插排序树查找
//L表示左儿子，R表示右儿子，E表示取当前节点
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const long maxn = 10000;

int a[200];
int tree[maxn];
int n;

int erfen(int q)
{
	int r,l,mid;
	l = 0;
	r = n-1;
	while(1)
	{
		mid = (r+l)/2;
		if(q>a[mid]) l = mid;
		if(q<a[mid]) r = mid;
		if(q == a[mid]) return mid+1;
	}
}

void TreeSerch(int q)
{
	int tot = 1;
	while(1)
	{
		if(tree[tot] == q) 
		{
		cout<<"E"<<endl;
		break;
		}
		if(tree[tot] > q)
		{
		cout<<"L";
		tot = 2*tot;
		continue;
		}
		if(tree[tot] < q)
		{
		cout<<"R";
		tot = 2*tot+1;
		continue;
		}
	}
}

int main()
{
	int q;
	int ch;
	int tot;
	cout<<"请输入一个顺序队列的个数(二分查找) :";
	cin>>n;
	cout<<"请输入元素 :";
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	cout<<"请输入查找的元素 :";
	cin>>q;
	cout<<"该元素在顺序队列的位置是 :"<<erfen(q)<<endl;
    cout<<"请输入一个队列的元素(二插排序树)，以-1结束 :"<<endl;
	for(int j = 0 ; j < maxn ; j++) tree[j] = -1;
	while(1)
	{
		cin>>ch;
		if(ch<0) break;
		tot = 1;
		while(1)
		{
			if(tree[tot] == -1)
			{
				tree[tot] = ch;
				break;
			}
			if(tree[tot]>ch)
			{
				tot = 2*tot;
				continue;
			}
			if(tree[tot]<ch)
			{
				tot = 2*tot+1;
				continue;
			}
		}
	}
	cout<<"请输入查找的元素 :";
	cin>>q;
	cout<<"该元素在顺序队列的位置是 :";
	TreeSerch(q);

	return 0;
}