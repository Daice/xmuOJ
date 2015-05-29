#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
struct nn
{
	char name[16];
	int s;
	int e;
};
struct nn* na;

int cmp(const void *a,const void *b)
{
	return (*(nn*)a).e<(*(nn*)b).e?-1:1;
}
int main()
{
	cin>>n;
	na=new struct nn[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>na[i].name;
		int a,b,c,d;
		scanf("%d:%d%d:%d",&a,&b,&c,&d);
		na[i].s=a*60+b;
		na[i].e=c*60+d;
	}	
	qsort(na+1,n,sizeof(na[1]),cmp);
	int i=1,mark=1,x[1001];
	for(int m=2;m<=n;m++)
	{
		if(na[m].s>=na[i].e)
		{
			i=m;
			x[mark++]=m;

		}
	}
	cout<<mark<<endl;
	cout<<na[1].name;
	for(int j=1;j<=mark;j++)
		cout<<" "<<na[x[j]].name;
	cout<<endl;
	return 0;
}
