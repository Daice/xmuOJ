#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;

LL quick_mod(LL a, LL b, LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

struct T
{
    LL p, d;
};

LL w;

T multi_er(T a, T b, LL m)
{
    T ans;
    ans.p = (a.p * b.p % m + a.d * b.d % m * w % m) % m;
    ans.d = (a.p * b.d % m + a.d * b.p % m) % m;
    return ans;
}

T power(T a, LL b, LL m)
{
    T ans;
    ans.p = 1;
    ans.d = 0;
    while(b)
    {
        if(b & 1)
        {
            ans = multi_er(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi_er(a, a, m);
    }
    return ans;
}

LL Legendre(LL a, LL p)
{
    return quick_mod(a, (p-1)>>1, p);
}

LL mod(LL a, LL m)
{
    a %= m;
    if(a < 0) a += m;
    return a;
}

LL Solve(LL n,LL p)
{
    if(p == 2) return 1;
    if (Legendre(n, p) + 1 == p)
        return -1;
    LL a = -1, t;
    while(true)
    {
        a = rand() % p;
        t = a * a - n;
        w = mod(t, p);
        if(Legendre(w, p) + 1 == p) break;
    }
    T tmp;
    tmp.p = a;
    tmp.d = 1;
    T ans = power(tmp, (p + 1)>>1, p);
    return ans.p;
}

int main()
{
        int n, p;
		cin>>n>>p;
        n %= p;
        int a = Solve(n, p);
        if(a == -1)
            cout<<"No"<<endl;
		else
		{
			int b = p - a;
			if(a > b) swap(a, b);
			if(a == b)
				cout<<"Yes"<<endl;
			else
				cout<<"Yes"<<endl;
		}
    return 0;
}

