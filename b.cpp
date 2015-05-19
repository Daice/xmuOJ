#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long int com(long long int n,long long int p)
{
		long long int s=1;
		long long int r=0,k=1,temp=0;
		for(long long int j=1;j<=n/2;j++)
		{
			for(;r<j;r++)
				s*=(n-r);
			for(;k<j&&s%j==0;k++)
				s/=k;
			temp+=(2*s)%p;
		}
		if(n%2==0)
			return temp;
		else
		{
			s*=(n-r);
			s/=k;
			temp+=s%p;
			return temp;
		}
}
int main()
{
	int t,*aa;
	long long int *n,*p;
	cin>>t;
	aa=new int[t];
	n=new long long int[t];
	n=new long long int[t];
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>p[i];
	}
	for(int i=0;i<t;i++)
	{
		long long int a,b,r;
		if(n[i]>p[i])
		{a=n[i];b=p[i];}
		else
		{a=p[i];b=n[i];}
		r=b;
		while(r!=0)
		{r=a%b;a=b;b=r;}
		n[i]/=a;
		p[i]/=a;
		n[i]%=p[i];
 		if(n[i]==4)
			aa[i]=38%p[i];
		else
		{
			long int tp=com(n[i],p[i]);
			aa[i]=(tp%p[i])*a;	
		}
	}
	for(int i=0;i<t;i++)
		cout<<aa[i]<<endl;
}
