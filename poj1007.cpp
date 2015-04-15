#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int i,j,k,m,n;
	char str[102][53];
	cin>>m>>n;
	for(i=0;i<n;i++)
	{
		cin>>str[i];
		str[i][m+2]='0';
		for(j=0;j<m-1;j++)
			for(k=j+1;k<m;k++)
				if(str[i][k]<str[i][j])
					str[i][m+2]++;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(str[j][m+2]<str[i][m+2])
			{
				for(k=0;k<m+3;k++)
				{str[n+1][k]=str[i][k];
				str[i][k]=str[j][k];
				str[j][k]=str[n+1][k];}	
			}
		}
	for(k=0;k<n;k++)
		cout<<str[k]<<endl;
	return 0;
}


