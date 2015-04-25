#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;
int v;
int *weight;
int *value;
int *f;
int **g;
void Initdata()
{
	cin>>n>>v;
	weight=new int[n+1];
	value=new int[n+1];
	f=new int[v+1];
	g=new int*[n+1];
	for(int i=0;i<=n;i++)
		g[i]=new int[v+1];
	for(int i=1;i<=n;i++)
		cin>>weight[i];
	for(int j=1;j<=n;j++)
		cin>>value[j];
}
int max(int x,int y)
{
	return x>y?x:y;
}

void Knapsack()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
//	for(int i=1;i<=n;i++)       //不必全满
//		for(int j=v;j>=weight[i];j--)
//			f[j]=max(f[j],f[j-weight[i]]+value[i]);
//	for(int i=1;i<=n;i++)       //恰好满
//		for(int j=weight[i];j<=v;j++)
//			f[j]=max(f[j],f[j-weight[i]]+value[i]);
	for(int i=1;i<=n;i++)
		for(int j=v;j>=weight[i];j--)
		{
			if(f[j]<f[j-weight[i]]+value[i])
			{
				f[j]=f[j-weight[i]]+value[i];
				g[i][j]=1;
			}
		}
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
void printnum(int i,int j)
{
	int k=0;
	while(i)
	{
		if(g[i][j]==1)
		{
			k++;
			j=j-weight[i];
		}
		i--;
	}
	cout<<k<<endl;
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
	if(g[i][j]==0)
	{
		print2(i-1,j);
	}
}
int main()
{
	Initdata();
	Knapsack();
//	cout<<"逆序输出:";
//	print1();
//	cout<<"\n顺序输出:";
	printnum(n,v);
	print2(n,v);
	cout<<endl;
	return 0;
}
