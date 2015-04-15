#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long a[10010];
int main()
{
	int n;
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",a[n/2]);
	}
	return 0;
}
