#include<iostream>
#include<cstring>
#define Maxm 501
using namespace std;
int p,q,k,m;
int Vertex,Line[Maxm];
int Path[Maxm][Maxm],Dist[Maxm][Maxm];
void Root(int p,int q)
{
	if(Path[p][q]>0)
	{
		Root(p,Path[p][q]);
		Root(Path[p][q],q);
	}
	else
	{Line[k]=q;k++;}
}
int main()
{
	memset(Path,0,sizeof(Path));
	memset(Dist,0,sizeof(Dist));
	cin>>Vertex;
	for(p=1;p<=Vertex;p++)
		for(q=1;q<=Vertex;q++)
			cin>>Dist[p][q];
	for(k=1;k<=Vertex;k++)
		for(p=1;p<=Vertex;p++)
			if(Dist[p][k]>0)
				for(q=1;q<=Vertex;q++)
					if(Dist[k][q]>0)
					{
						if(((Dist[p][q]>Dist[p][k]+Dist[k][q])||(Dist[p][q]==0))&&(p!=q))
						{
							Dist[p][q]=Dist[p][k]+Dist[k][q];
							Path[p][q]=k;
						}
					}
	for(p=1;p<=Vertex;p++)
	{
		for(q=p+1;q<=Vertex;q++)
		{
			cout<<"Source:"<<p<<"Target"<<q<<endl;
			cout<<"Distance:"<<Dist[p][q]<<endl;
			cout<<"Path:"<<p;
			k=2;
			Root(p,q);
			for(m=2;m<=k-1;m++)
				cout<<"-->"<<Line[m];
			cout<<endl;
		}
	}
return 0;
}
