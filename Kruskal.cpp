#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN_E 100000
#define MAXN_V 100000
using namespace std;
struct Edge{
    int fm,to,dist;
}e[MAXN_E];
int fa[MAXN_V],n,m;
bool cmp(Edge a,Edge b){
    return a.dist < b.dist;
}
int getfa(intx){//getfa是在并查集森林中找到x的祖先
    if(fa[x]==x) return fa[x];
    else return fa[x] = getfa(fa[x]);
}
int same(int x,int y){
    return getfa(x)==getfa(y);
}
void merge(intx,inty){
    int fax=getfa(x),fay=getfa(y);
    fa[fax]=fay;
}
int main(){
    scanf("%d%d",&n,&m);//n为点数，m为边数
    for(inti=1;i<=m;i++)
    scanf("%d%d%d",&e[i].fm,&e[i].to,&e[i].dist);//用边集数组存放边，方便排序和调用
    sort(e+1,e+m+1,cmp);//对边按边权进行升序排序
    for(int i=1;i<=n;i++)
    fa[i]=i;
    int rst=n,ans=0;//rst表示目前的点共存在于多少个集合中，初始情况是每个点都在不同的集合中
    for(int i=1;i<=m && rst>1;i++)
    {
        int x=e[i].fm,y=e[i].to;
        if(same(x,y)) continue;//same函数是查询两个点是否在同一集合中
        else
        {
            merge(x,y);//merge函数用来将两个点合并到同一集合中
            rst--;//每次将两个不同集合中的点合并，都将使rst值减1
            ans+=e[i].dist;//这条边是最小生成树中的边，将答案加上边权
        }
    }
    printf("%d\n",ans);
    return0;
}
