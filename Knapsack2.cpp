#include<iostream>
using namespace std;

const int minnum=0x80000000;

const int n=3;
const int v=5;
int weight[n+1]={0,3,2,2};
int value[n+1]={0,5,10,20};

int f[v+1]={0};

int max(int x,int y)
{
	return x>y?x:y;
}

int Knapsack()
{
	for(int i=0;i<=v;i++)
		f[i]=minnum;
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=v;j>=weight[i];j--)
			f[j]=max(f[j],f[j-weight[i]]+value[i]);
	return f[v];
}

int main()
{
	cout<<Knapsack()<<endl;
	return 0;
}
