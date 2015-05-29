#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 105
int main()
{
	int n;
	int a[MAX][MAX]={0};
	int colsum[MAX][MAX]={0};
	int max=0,sum;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j-1];
			colsum[i][j]=colsum[i][j-1]+a[i][j-1];
		}
	for(int i=0;i<n;i++)
		for(int j=i;j<=n;j++)//从第i行到第j行
		{
			sum=0;
			for(int k=0;k<n;k++)//每列的和
			{
				sum+=colsum[k][j]-colsum[k][i];
				if(sum<0) sum=0;
				else if(sum>max) max=sum;
			}
		}
	cout<<max<<endl;
	return 0;
}
