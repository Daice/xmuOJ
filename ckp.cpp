#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define Max(a,b) (a>b?a:b)
string name[1001];
int s[1001],e[1001],f[1400],v[1001];
int main()
{
	int i,j;
	int a,b,c,d;
	int n,min,max;
	while(cin>>n)
	{
		min=1400;max=0;
	for(i=0;i<n;i++)
	{
	cin>>name[i];
	scanf("%d:%d%d:%d",&a,&b,&c,&d);
	s[i]=a*60+b;e[i]=c*60+d;
	//cout<<s[i]<<" "<<e[i]<<endl;
	min=min<e[i]?min:e[i];
	max=max>e[i]?max:e[i];
	}
	//cout<<min<<" "<<max<<endl;
	
	memset(f,0,sizeof(f));
	for(i=min;i<=max;i++)
	{
	for(j=0;j<n;j++)
	{
	if(i>=e[j])
	{
	f[i]=Max(f[i],f[s[j]]+1);
	}
	}
	}
	cout<<f[max]<<endl;
	memset(v,0,sizeof(v));
	a=0;
	for(i=max;i>=min;i--)
	for(j=0;j<n;j++)
	if(i>=e[j])
	{
		if(f[i]-1==f[s[j]])
		{v[a++]=j;i=s[j]+1;break;}
		
	}
	cout<<name[v[a-1]];
	for(i=a-2;i>=0;i--)
		cout<<" "<<name[v[i]];
	cout<<endl;
	}
return 0;
}
