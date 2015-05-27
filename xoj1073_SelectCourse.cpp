#include <queue>
#include <vector>
#include <cstdio>
#include<iostream>
using namespace std;
 
vector<int> nt[501];
char s[501][41];
int d[501];
int x[500];
 
void topological_sort(int n)
{
    int u, i, k = 0;
    queue<int> que;
    vector<int>::iterator it;
 
    for (i = 1; i <= n; i++)
        if (d[i] == 0)
            que.push(i);
    while (!que.empty()) {
        u = que.front();
        que.pop();
        x[k++] = u;
        for (it = nt[u].begin(); it != nt[u].end(); it++)
            if (--d[*it] == 0)
                que.push(*it);
    }
    if (k == n) {
        printf("%s", s[x[0]]);
        for (i = 1; i < n; i++)
            printf(" %s", s[x[i]]);
        printf("\n");
    } else {
        printf("Impossible!\n");
    }
}
 
int main(int argc, char *argv[])
{
    int n, m, i, j;
 
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%s", s[i]);
    for (i = 1; i <= n; i++) {
        scanf("%d", &m);
        d[i] = m;
        while (m--) {
            scanf("%d", &j);
            nt[j].push_back(i);
        }
    }
    topological_sort(n);
 
    return 0;
}
