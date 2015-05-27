
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define min(x,y) ((x<y)?(x):(y))
using namespace std;
const int MAX=0x5fffffff; 
int tab[250][250];  
int dis[250];  
int q[2000],h,r; 
int N,M,ANS; 
int BFS()
{
     int i,j;
     memset(dis,0xff,sizeof(dis)); 
     dis[1]=0;
     h=0;r=1;
     q[1]=1;
     while (h<r)
     {
           j=q[++h];
           for (i=1;i<=N;i++)
               if (dis[i]<0 && tab[j][i]>0)
               {
                  dis[i]=dis[j]+1; 
                  q[++r]=i;
               }
     }
     if (dis[N]>0)
        return 1;
     else
        return 0; 
}
 
int find(int x,int low) 
{
    int i,a=0;
    if (x==N)return low; 
    for (i=1;i<=N;i++)
    if (tab[x][i] >0 && dis[i]==dis[x]+1 && (a=find(i,min(low,tab[x][i])))) 
    {
       tab[x][i]-=a;
       tab[i][x]+=a;
       return a;
    }
    return 0;
    
}
int main()
{
    int i,j,f,t,flow,tans;
    memset(tab,0,sizeof(tab));
	cin>>M>>N;
    for (i=1;i<=M;i++)
    {
        scanf("%d%d%d",&f,&t,&flow);
        tab[f][t]+=flow;
    }
    ANS=0;
    while (BFS()) 
    {
          while(tans=find(1,0x7fffffff))ANS+=tans; 
    }
    printf("%d\n",ANS);
}
