#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

vector<int> nt[501];
char s[501][41];
int d[501];
int x[500];
int n;

void topological_sort()
{
	int k=0;
	queue<int> q;
	vector<int>::iterator it;
	for(int i=1;i<=n;i++)
		if(d[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		x[k++]=u;
		for(it=nt[u].begin();it!=nt[u].end();it++)
			if(--d[*it]==0)
				q.push(*it);
	}
	if(k==n)
	{
		for(int i=0;i<n-1;i++)
			cout<<s[x[i]]<<" ";
		cout<<s[x[n-1]]<<endl;
	}
	else
		cout<<"Impossible!"<<endl;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		int m=d[i];
		while(m--)
		{
			int j;
			cin>>j;
			nt[j].push_back(i);
		}
	}	
	topological_sort();
	return 0;
}
