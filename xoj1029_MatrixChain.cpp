#include <iostream>
#include <cstdio>
using namespace std;
#define INT_MAX 99999999
 
int f[201][201];
int p[201];
 
int main(int argc, char* argv[])
{
    int n, l, t;
    int i, j, k;
 
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
        scanf("%d", p + i);
 
    for (l = 2; l <= n; l++)
    for (j = l; j <= n; j++)
    {
        i = j - l + 1;
        f[i][j] = INT_MAX;
        for (k = i; k < j; k++) {
            t = f[i][k] + f[k+1][j] + p[i-1] * p[k] * p[j];
            if (t < f[i][j])
                f[i][j] = t;
        }
    }
    printf("%d\n", f[1][n]);
 
    return 0;
}
