#include<iostream>
#include<climits>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,*parent,graph[201][201];

bool bfs(int s,int t)
{
	bool visited[201];
	memset(visited,0,sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=1;v<=n;v++)
		{
			if(visited[v]==false&&graph[u][v]>0)
			{
				q.push(v);
				visited[v]=true;
				parent[v]=u;
			}
		}
	}
	return visited[t];
}
int FordFulkerson(int s,int t)
{
	int u,v;
	int max_flow=0;
	while(bfs(s,t))
	{
		int path_flow=INT_MAX;
		for(v=t;v!=s;v=parent[v])
		{
			u=parent[v];
			path_flow=min(path_flow,graph[u][v]);
		}
		for(v=t;v!=s;v=parent[v])
		{
			u=parent[v];
			graph[u][v]-=path_flow;
			graph[v][u]+=path_flow;
		}
		max_flow+=path_flow;
	}
	return max_flow;
}
int main()
{
	int s,t,flow;
	cin>>m>>n;
	parent=new int[n+1];
	memset(graph,0,sizeof(graph));
	for(int i=0;i<m;i++)
	{
		cin>>s>>t>>flow;
		graph[s][t]=flow;
	}
	cout<<FordFulkerson(1,n)<<endl;
	return 0;
}
