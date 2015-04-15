#include<iostream>
#include<cstdio>
using namespace std;
int d[1000000],w[1000000],p[1000000];
int main()
{
	int i,j,k=0,g=0,h=1;
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++)
			if (getchar()=='b') 
				d[1]=(d[1]<<1)+1; 
			else 
				d[1]=d[1]<<1;
			getchar();
	}
	p[1]=0;
	while(g<h){
		g++;
		if(d[g]==0||d[g]==(1<<16)-1) {
			printf("%d",w[g]);
			k=1;
			break;
		}
		if (h>990000) continue;
		for(i=p[g]+1;i<=16;i++){
			h++;
			w[h]=w[g]+1;
			p[h]=i;
			d[h]=d[g]^(1<<(16-i));
			if(i-4>=1) 
				d[h]^=1<<(16-i+4);
			if(i+4<=16) 
				d[h]^=1<<(16-i-4);
			if(i%4!=0) 
				d[h]^=1<<(16-i-1);
			if((i-1)%4!=0) 
				d[h]^=1<<(16-i+1); 
		}
	 }
	if (!k) 
		printf("Impossible");
	return 0;
}
