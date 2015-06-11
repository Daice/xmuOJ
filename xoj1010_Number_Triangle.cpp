#include<iostream>
using namespace std;

int n,t[1001][1001];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>t[i][j];
	for(int i=n;i>1;i--)
		for(int j=1;j<i;j++)
		{
			if(t[i][j]>t[i][j+1]) t[i-1][j]+=t[i][j];
			else t[i-1][j]+=t[i][j+1];
		}
	cout<<t[1][1]<<endl;
}
