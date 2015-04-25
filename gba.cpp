#include<stdio.h>
#include<stdlib.h>

void PrintKnapsack(int i,int j,int **g,int *cost)
{
	int k=0;
	while(i)
	{
		if(g[i][j]==1)
		{
			k++;
			j=j-cost[i];
		}
		i--;
	}
	printf("%d\n",k);
}
void PrintKnapsack_recursion(int i,int j,int **g,int *cost)
{
	if (i==0||j==0)
    {
        return;
    }
    if (g[i][j]==1)
    {
        PrintKnapsack_recursion(i-1,j-cost[i],g,cost);
        printf("%d ",i);
    }
	if(g[i][j]==0)
	{
		PrintKnapsack_recursion(i-1,j,g,cost);
	}
}
int main()
{
	int i,j,k;
	int *f,**g;
	int m,n;
	int *cost,*value;
	scanf("%d%d",&n,&m);
	f=(int*)malloc(sizeof(int)*(m+1));
	g=(int**)malloc(sizeof(int*)*(n+1));
	cost=(int*)malloc(sizeof(int)*(n+1));
	value=(int*)malloc(sizeof(int)*(n+1));
	for(i=1;i<n+1;i++)
		scanf("%d",&cost[i]);
	for(j=1;j<n+1;j++)
		scanf("%d",&value[j]);
	for(k=0;k<m+1;k++)
		f[k]=0;
	for(i=0;i<n+1;i++)
	{
		g[i]=(int*)malloc(sizeof(int)*(m+1));
		for(j=0;j<m+1;j++)
			g[i][j]=0;
	}
	for(i=1;i<=n;i++)
		for(j=m;j>=cost[i];j--)
		{
			if(f[j]<f[j-cost[i]]+value[i])
			{
				f[j]=f[j-cost[i]]+value[i];
				g[i][j]=1;
			}
		}
	PrintKnapsack(n,m,g,cost);
	PrintKnapsack_recursion(n,m,g,cost);
	printf("\n");
	return 0;
}
