#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 110
int map[MAXN][MAXN], lowcost[MAXN];
bool visit[MAXN];
int nodenum, sum;

void prim()
{
	int temp, k;
	sum = 0;
	memset(visit, false, sizeof(visit)); //初始化visit
	visit[1] = true;
	for(int i = 1; i <= nodenum; ++i) //初始化lowcost[i]
		lowcost[i] = map[1][i];
	for(int i = 1; i <= nodenum; ++i)//找生成树集合点集相连最小权值的边
	{
		temp = INF;
		for(int j = 1; j <= nodenum; ++j)
			if(!visit[j] && temp > lowcost[j])
				temp = lowcost[k = j];
		if(temp == INF) break;
		visit[k] = true; //加入最小生成树集合
		sum += temp;//记录权值之和
		for(int j = 1; j <= nodenum; ++j) //更新lowcost数组
			if(!visit[j] && lowcost[j] > map[k][j])
				lowcost[j] = map[k][j];
	}
}

int main()
{
	int a, b, cost, edgenum;
	while(scanf("%d", &nodenum) && nodenum)
	{
		memset(map, INF, sizeof(map));
		edgenum = nodenum * (nodenum - 1) / 2;
		for(int i = 1; i <= edgenum; ++i) //输入边的信息
		{
			scanf("%d%d%d", &a, &b, &cost);
			if(cost < map[a][b])
				map[a][b] = map[b][a] = cost;
		}
		prim();
		printf("%d\n", sum); //最小生成树权值之和
	}
	return 0;
}
