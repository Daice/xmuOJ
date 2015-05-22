#include <cstdio>
#include <algorithm>
using namespace std;
 
int f[2][1001];
int a[2][1001];
int t[2][1000];
int e[2], x[2];
 
int main(int argc, char* argv[])
{
    int n, i, j;
 
    scanf("%d", &n);
    scanf("%d %d", e, e + 1);
    scanf("%d %d", x, x + 1);
    for (i = 0; i < 2; i++)
    for (j = 1; j <= n; j++)
        scanf("%d", &a[i][j]);
    for (i = 0; i < 2; i++)
    for (j = 1; j < n; j++)
        scanf("%d", &t[i][j]);
 
    f[0][1] = e[0] + a[0][1];
    f[1][1] = e[1] + a[1][1];
    for (i = 2; i <= n; i++) {
        f[0][i] = min(f[0][i-1], f[1][i-1] + t[1][i-1]) + a[0][i];
        f[1][i] = min(f[1][i-1], f[0][i-1] + t[0][i-1]) + a[1][i];
    }
    printf("%d\n", min(f[0][n] + x[0], f[1][n] + x[1]));
 
    return 0;
}
