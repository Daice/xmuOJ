#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define m 10
int matrix[m][m];
int visited[m+1];
void gt_BFS()
{
	memset(visited,0,sizeof(visited));
	visited[1]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int top=q.front();
		cout<<top<<" ";
		q.pop();
		for(int i=1;i<=m;i++)
		{
			if(visited[i]==0&&matrix[top-1][i-1]==1)
			{
				visited[i]=1;
				q.push(i);
			}
		}
	}
}
int main()
{
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];
	gt_BFS();
	return 0;
}
