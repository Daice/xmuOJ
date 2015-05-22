#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
//long int *num;
//long int **data;
void InitData()
{
	cin>>T;
	long int *num=new long int[T];
	long long int **data=new long long int*[T];
	for(int i=0;i<T;i++)
	{
		cin>>num[i];
		data[i]=new long long int[num[i]];
		for(long int j=0;j<num[i];j++)
			cin>>data[i][j];
	}
	for(int i=0;i<T;i++)
	{
		int a[3]={0,0,0};
		for(long int j=0;j<num[i];j++)
		{
			if(data[i][j]%2==1)
				a[0]=1;
			else
			{
				long long int m=data[i][j];
				int count=0;
				for(;m%2!=1;)
				{
					m/=2;
					count++;
				}
				if(count%2==0)a[1]++;
				else a[2]++;
			}
		}
		//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		if(a[0]==0)
		{
			if(a[1]==0)cout<<"Second"<<endl;
			else cout<<"First"<<endl;
		}
		else
		{
			if(a[1]==0)cout<<"First"<<endl;
			else cout<<"Second"<<endl;
		}
	}
}
int main()
{
	InitData();
}
