#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int m1,n1,m2,n2;
	int a[101][101],b[101][101],c[101][101];
	memset(c,0,sizeof(c));
	cin>>m1>>n1;
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=n1;j++)
			cin>>a[i][j];
	cin>>m2>>n2;
	for(int i=1;i<=m2;i++)
		for(int j=1;j<=n2;j++)
			cin>>b[i][j];
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=n2;j++)
			for(int k=1;k<=n1;k++)
				c[i][j]+=a[i][k]*b[k][j];
	for(int i=1;i<=m1;i++)
	{
		for(int j=1;j<n2;j++)
			cout<<c[i][j]<<" ";
		cout<<c[i][n2]<<endl;
	}
	return 0;
}
