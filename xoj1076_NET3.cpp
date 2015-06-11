#include<iostream>
#include<algorithm>
using namespace std;

struct edge
{
	int s,e,d;
}e[200000];

int p[100001];
int n,m;

int cmp(const struct edge& a,const struct edge& b)
{
	return a.d<b.d;
}

int find(int x)
{
	int r=x;
	while(r!=p[r]) r=p[r];
	int i=x,j;
	while(p[i]!=r) {j=p[i];p[i]=r;i=j;}
	return r;
}

void join(int x,int y)
{
	if(x!=y)
		p[y]=x;
}

int Krual()
{
	int u,v,sum=0,mark=0;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=0;i<m;i++)
	{
		u=find(e[i].s);
		v=find(e[i].e);
		if(u!=v)
		{
			sum+=e[i].d;
			if(++mark==n-1)
				return sum;
			join(u,v);
		}
	}
	return -1;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>e[i].s>>e[i].e>>e[i].d;
	sort(e,e+m,cmp);
	cout<<Krual()<<endl;
	return 0;
}
