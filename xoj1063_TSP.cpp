#include<iostream>
using namespace std;
int bestx[13],w[13][13],cw=0,bestw=99999999,x[13],n;

int b(int i)
{
	int m,ms=0;
	for(int j=i;j<=n;j++)
	{
		
		m=w[x[j]][1];
		for(int p=2;p<=n;p++)
			if(w[x[j]][p]!=0&&w[x[j]][p]<m)
				m=w[x[j]][p];
		ms+=m;
	}
	return ms;	
}
void BacktrackTSP(int i)
{
	if(i==n)
	{
		if(cw+w[x[n-1]][x[n]]+w[x[n]][1]<bestw)
		{
			bestw=cw+w[x[n-1]][x[n]]+w[x[n]][1];
			for(int j=1;j<=n;j++)
				bestx[j]=x[j];
		}
	}
	else
	{
		for(int j=i;j<=n;j++)
			if(cw+w[x[i-1]][x[j]]<bestw)
			{
				int t;t=x[i];x[i]=x[j];x[j]=t;
				cw+=w[x[i-1]][x[i]];
				BacktrackTSP(i+1);
				cw-=w[x[i-1]][x[i]];
				t=x[i];x[i]=x[j];x[j]=t;
			}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		x[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>w[i][j];
	BacktrackTSP(2);
	cout<<bestw<<endl;
	return 0;
}
