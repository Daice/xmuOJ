#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,W,f;
struct good
{
	int w;
	int v;
	double sigma;
};
struct good* gd;
bool cmp(const struct good &a,const struct good &b)
{
	return a.sigma>=b.sigma;
}
void Initdata()
{
	cin>>n>>W;
	gd=new struct good[n+1];
	for(int i=1;i<=n;i++)
		cin>>gd[i].w;
	for(int j=1;j<=n;j++)
		cin>>gd[j].v;
	for(int i=1;i<=n;i++)
		gd[i].sigma=gd[i].v/gd[i].w;
	sort(gd+1,gd+n+1,cmp);
}
void greedy2kp()
{
	int mark=W;
	f=0;
	for(int i=1;i<=n;i++)
	{
		if((mark-=gd[i].w)>=0)
		{
			f+=gd[i].v;
		}
		else
		{
			f+=(mark+gd[i].w)*gd[i].sigma;
			break;		
		}
	}	
}
int main()
{
	Initdata();
	greedy2kp();
	cout<<f<<endl;
}
