#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,W;
double f;
struct good
{
	double w;
	double v;
	double sigma;
};
struct good* gd;
int cmp(const void *a,const void *b)
{
	return (*(good*)a).sigma<(*(good*)b).sigma?1:-1;
}
void Initdata()
{
	cin>>W>>n;
	gd=new struct good[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>gd[i].w>>gd[i].v; 
		gd[i].sigma=gd[i].v/gd[i].w;
	}		 
	qsort(gd+1,n,sizeof(gd[1]),cmp);	
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
	printf("%0.6f\n",f);
}
