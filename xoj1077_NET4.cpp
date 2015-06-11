#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

struct node
{
	node(int num,int len)
	{
		this->num=num;this->len=len;
	}
	int num,len;
};

vector<node> nt[100001];
int d[100001],b[100001];
int m,n;

int spfa()
{
	queue<int> q;
	vector<node>::iterator it;
	d[1]=0;b[1]=1;
	q.push(1);
	for(int i=2;i<=n;i++)
	{
		d[i]=INT_MAX;b[i]=0;
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		b[u]=0;
		for(it=nt[u].begin();it!=nt[u].end();it++)
		{
			if(d[it->num]>d[u]+it->len)
			{
				d[it->num]=d[u]+it->len;
				if(!b[it->num])
				{
					b[it->num]=1;
					q.push(it->num);
				}
			}
		}
	}
	return d[n]==INT_MAX?-1:d[n];
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,len;
		cin>>u>>v>>len;
		nt[u].push_back(node(v,len));
		nt[v].push_back(node(u,len));
	}
	cout<<spfa()<<endl;
	return 0;
}
