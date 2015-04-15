#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define max 999999
int n,*p;
int m[100][100],s[100][100];
void Initdata()
{
	cin>>n;
	p=(int*)malloc(sizeof(int)*(n+1));
	for(int i=0;i<=n;i++)
		cin>>p[i];
}
void DPMatrixChain()
{
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int c=2;c<=n;c++)
		for(int i=1;i<=n-c+1;i++)
		{
			int j=i+c-1;
			m[i][j]=max;
			for(int k=i;k<=j-1;k++)
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{m[i][j]=q;s[i][j]=k;}
			}
		}
}
void PrintParens(int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		PrintParens(i,s[i][j]);
		PrintParens(s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
	Initdata();
	DPMatrixChain();
	PrintParens(1,n);
	cout<<endl;
	return 0;	
}
