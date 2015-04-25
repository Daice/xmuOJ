#include<iostream>
#include<cstdio>
using namespace std;
#define max 1000000
int arcs[10][10];
int d[10];
int p[10][10];
int final[10];
int n=0;
int v0=0;
int v,w;
void shortestPath_dij()
{
	for(v=0;v<n;v++)
	{
		final[v]=0;
		d[v]=arcs[v0][v];
		for(w=0;w<n;w++)
			p[v][w]=0;
		if(d[v]<max)
		{
			p[v][v0]=1;
			p[v][v]=1;
		}
	}
	d[v0]=0;
	final[v0]=0;
	for(int i=1;i<n;i++)
	{
		int min=max;
		for(w=0;w<n;w++)
		{
			if(!final[w])
			{
				if(d[w]<min)
				{
					v=w;
					min=d[w];
				}
			}
		}
		final[v]=1;
		for(w=0;w<n;w++)
		{
			if(!final[w]&&(min+arcs[v][w]<d[w]))
			{
				d[w]=min+arcs[v][w];
				p[w][w]=1;
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arcs[i][j];
	shortestPath_dij();
	for(int i=0;i<n;i++)
		cout<<d[i]<<" ";
	return 0;
}
