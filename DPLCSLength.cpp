#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int m,n,c[100][100],b[100][100];
char x[]="AABCBDAB",y[]="BBDCABA";

void Initdata()
{
	cout<<"please enter m and n:"<<endl;
	cin>>m>>n;
//	x=(char*)malloc(sizeof(char)*(m+1));
//	y=(char*)malloc(sizeof(char)*(n+1));
//	cout<<"please enter x:"<<endl;
//	for(int i=1;i<=m;i++)
//		x[i]=getchar();
//	cout<<"please enter y:"<<endl;
//	for(int i=1;i<=n;i++)
//		y[i]=getchar();
}

void DPLCSLength()
{
	for(int i=1;i<=m;i++)
		c[i][0]=0;
	for(int i=0;i<=n;i++)
		c[0][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else
			{	if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]=2;
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]=3;
				}
			}
		}
}

void PrintLCS(int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==1)
	{
		PrintLCS(i-1,j-1);
		cout<<x[i];
	}
	else
	{
		if(b[i][j]==2)
			PrintLCS(i-1,j);
		else
			PrintLCS(i,j-1);
	}	
}
int main()
{
	Initdata();
	DPLCSLength();
	PrintLCS(m,n); 
	return 0;
}
