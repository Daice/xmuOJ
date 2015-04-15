#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,e1,e2,x1,x2,f,l;
int *a1,*a2,*f1,*f2,*t1,*t2,*l1,*l2;

void Initdata()
{
	cout<<"enter ei"<<endl;
	cin>>e1>>e2;
	cout<<"enter xi"<<endl;
	cin>>x1>>x2;
	cout<<"enter n"<<endl;
	cin>>n;
	a1=(int*)malloc(sizeof(int)*(n+1));
	a2=(int*)malloc(sizeof(int)*(n+1));
	l1=(int*)malloc(sizeof(int)*(n+1));
	l2=(int*)malloc(sizeof(int)*(n+1));
	f1=(int*)malloc(sizeof(int)*(n+1));
	f2=(int*)malloc(sizeof(int)*(n+1));
	t1=(int*)malloc(sizeof(int)*(n+1));
	t2=(int*)malloc(sizeof(int)*(n+1));
	cout<<"enter a1"<<endl;
	for(int i=1;i<=n;i++)
		cin>>a1[i];
	cout<<"enter a2"<<endl;
	for(int i=1;i<=n;i++)
		cin>>a2[i];
	cout<<"enter t1"<<endl;
	for(int i=1;i<n;i++)
		cin>>t1[i];
	cout<<"enter t2"<<endl;
	for(int i=1;i<n;i++)
		cin>>t2[i];
}

void DPFastWay()
{
	f1[1]=e1+a1[1];
	f2[1]=e2+a2[2];
	for(int j=2;j<=n;j++)
	{
		if(f1[j-1]+a1[j]<=f2[j-1]+t2[j-1]+a1[j])
		{
			f1[j]=f1[j-1]+a1[j];
			l1[j]=1;
		}
		else
		{
			f1[j]=f2[j-1]+t2[j-1]+a1[j];
			l1[j]=2;
		}
		if(f2[j-1]+a2[j]<=f1[j-1]+t1[j-1]+a2[j])
		{
			f2[j]=f2[j-1]+a2[j];
			l2[j]=2;
		}
		else
		{
			f2[j]=f1[j-1]+t1[j-1]+a2[j];
			l2[j]=1;
		}
	}
	if(f1[n]+x1<=f2[n]+x2)
	{
		f=f1[n]+x1;
		l=1;
	}
	else
	{
		f=f2[n]+x2;
		l=2;
	}
}

void PrintStation()
{
	int i=l;
	cout<<"line"<<i<<",station"<<n<<endl;
	for(int j=n;j>1;j--)
	{
		if(i==1)
		{
			i=l1[j];
			cout<<"line"<<i<<",station"<<j-1<<endl;
		}
		else
		{
			i=l2[j];
			cout<<"line"<<i<<",station"<<j-1<<endl;
		}
	}
}
int main()
{
	Initdata();
	DPFastWay();
	PrintStation();
	cout<<"least time:"<<f<<endl;
	return 0;
}

