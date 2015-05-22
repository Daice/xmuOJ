#include<iostream>
#include<cmath>
using namespace std;

int n;
int sum=0;
int *x;
int *out;

bool place(int k)
{
	for(int i=1;i<k;i++)
	{
		if(x[i]==x[k]||abs(i-k)==abs(x[i]-x[k]))
			return false;
	}
	return true;
}	

void BacktrackNqueens()
{
	x[1]=0;
	int k=1,t=1;
	while(k>0)
	{
		while(x[k]<=n-1)
		{
			x[k]+=1;
			if(place(k))
			{
				if(k==n)
				{
					sum++;
					if(t==1)
					{for(int i=1;i<=n;i++)out[i]=x[i];t++;}
				}
				else
				{
					k++;
					x[k]=0;
				}
			}
		}
		k--;
	}
}

int main()
{
	cin>>n;
	x=new int[n+1];
	out=new int[n+1];
	BacktrackNqueens();
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<out[i]<<endl;
	return 0;
}
