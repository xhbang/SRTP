//��̬Ϊ���ֲ���
//��̬Ϊ��������������
//L��ʾ����ӣ�R��ʾ�Ҷ��ӣ�E��ʾȡ��ǰ�ڵ�
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
	cout<<"������һ��˳����еĸ���(���ֲ���) :";
	cin>>n;
	cout<<"������Ԫ�� :";
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	cout<<"��������ҵ�Ԫ�� :";
	cin>>q;
	cout<<"��Ԫ����˳����е�λ���� :"<<erfen(q)<<endl;
    cout<<"������һ�����е�Ԫ��(����������)����-1���� :"<<endl;
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
	cout<<"��������ҵ�Ԫ�� :";
	cin>>q;
	cout<<"��Ԫ����˳����е�λ���� :";
	TreeSerch(q);

	return 0;
}