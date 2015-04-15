#include<iostream>
#include<cstring>
using namespace std;

const int n=3;
const int v=50;
int weight[n+1]={0,10,20,30};
int value[n+1]={0,60,100,120};
int f[v+1]={0};
int g[n+1][v+1]={{0}};
int max(int x,int y)
{
	return x>y?x:y;
}

int Knapsack()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
//	for(int i=1;i<=n;i++)       //不必全满
//		for(int j=v;j>=weight[i];j--)
//			f[j]=max(f[j],f[j-weight[i]]+value[i]);
//	for(int i=1;i<=n;i++)       //恰好满
//		for(int j=weight[i];j<=v;j++)
//			f[j]=max(f[j],f[j-weight[i]]+value[i]);
//	for(int i=1;i<=n;i++)
//		for(int j=v;j>=weight[i];j--)
//		{
//			if(f[j]<f[j-weight[i]]+value[i])
//			{
//				f[j]=f[j-weight[i]]+value[i];
//				g[i][j]=1;
//			}
//		}
	for(int i=1;i<=n;i++)
		for(int j=v;j>=1;j--)
		{
			if(j>=weight[i])
				f[j]=max(f[j],f[j-weight[i]]+value[i]);
			else
				f[j]=max(f[j],j*value[i]/weight[i]);
		}
	return f[v];
}

void print1()
{
	int i=n;
	int j=v;
	while(i)
	{
		if(g[i][j]==1)
		{
			cout<<i<<" ";
			j-=weight[i];
		}
		i--;
	}
}
void print2(int i,int j)
{
	if(i==0||j==0)
		return;
	if(g[i][j]==1)
	{
		print2(i-1,j-weight[i]);
		cout<<i<<" ";
	}
}
int main()
{
	cout<<Knapsack()<<endl;
//	cout<<"逆序输出:";
//	print1();
//	cout<<"\n顺序输出:";
//	print2(n,v);
//	cout<<endl;
	return 0;
}
