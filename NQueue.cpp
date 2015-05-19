#include <iostream>
#include<cmath>
using namespace std;

int N;
int sum=0;
int *x=new int[N+1];

bool place(int k)
{
	int i;
	for(i=1; i<k; i++)
	{
		if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))
			return false;
	}
	return true;
}

void backtrack2()//迭代回溯
{
	int i;
	x[1]=0;
	int k=1;
	while(k>0)
	{
		x[k]+=1;//当前列加1的位置开始搜索
		while((x[k]<=N) && !place(k))//当前列位置是否满足条件
			x[k]+=1;//不满足条件，继续搜索下一个位置

		if(x[k]<=N)//存在满足条件的列
		{
			if(k==N)//是最后一个皇后，完成搜索
			{
				for(i=1; i<=N; i++)
					cout<<i<<" "<<x[i]<<endl;
				//cout<<endl;
				return;
				sum++;

			}
			else//不是，则处理下一个皇后
			{
				k++;
				x[k]=0;
			}
		}
		else//回溯
		{
			k--;
		}

	}
}

int main()
{
	cin>>N;
	backtrack2();
//	cout<<sum<<endl;
	
}


