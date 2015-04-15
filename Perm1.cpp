#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[1000];

void output(int *a)
{
	for(int i=1;i<=n;i++)
		cout<<a[i];
	cout<<endl;
}

void swap(int i,int j)
{
	int key;
	key=a[i];
	a[i]=a[j];
	a[j]=key;
}
void Perm1(int m)
{
	if(m==n)
		output(a);
	else
		for(int j=m;j<=n;j++)
		{
			swap(j,m);
			Perm1(m+1);
			swap(j,m);
		}
}

void RePerm1(int m)
{
	if(m==n)
		output(a);
	else
		for(int j=m;j<=n;j++)
		{
			swap(j,m);
			int t=a[j];
			int k=j;
			for(;k>m+1;k--)
				a[k]=a[k-1];
			a[k]=t;
			RePerm1(m+1);
			for(;k<j;k++)
				a[k]=a[k+1];
			a[k]=t;
			swap(j,m);
		}
}
void GeneratingPerm1()
{
	for(int i=1;i<=n;i++)
		a[i]=i;
	RePerm1(1);
}

int main()
{
	cin>>n;
	GeneratingPerm1();
	return 0;
}
