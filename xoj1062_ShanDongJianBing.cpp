#include <stdio.h>
#include <stdlib.h>
int coin[]={500,100,50,10,5,1};
int sum[6];
int pcs=25,all=1000;
int main()
{
    int i,n,m,j,cout=0;
    scanf("%d",&n);
    for(i=0;i<6;i++)scanf("%d",&sum[i]);
    m=all-pcs*n;
    j=0;
    for(i=0;i<6;i++)
    {
        if(!m)
        break;
        if(m>=coin[i])
        {
            j=m/coin[i];
            if(sum[i]>=j)
            {
                cout+=j;
                m-=j*coin[i];

            }
            else if(sum[i]>0)
            {
                cout+=sum[i];
                m-=sum[i]*coin[i];
            }

        }
    }
    if(m>0)
    printf("-1\n");
    else
    printf("%d\n",cout);

    return 0;
}
