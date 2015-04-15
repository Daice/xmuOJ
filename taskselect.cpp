#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct task
{
	int s;
	int f;
};
struct task* tk;
bool cmp(const task &a,const task &b)
{
	return a.f<=b.f;
}
void Initdata()
{
	cin>>n;
	tk=new struct task[n];
	for(int i=0;i<n;i++)
		cin>>tk[i].s;
	for(int j=0;j<n;j++)
		cin>>tk[j].f;
	sort(tk,tk+n,cmp);
}
void greedytaskselect()
{
	int i=0;
	cout<<i;
	for(int j=1;j<n;j++)
	{
		if(tk[j].s>=tk[i].f)
		{
			cout<<" "<<j;
			i=j;
		}
	}
	cout<<endl;
}
int main()
{
	Initdata();
	greedytaskselect();
}
