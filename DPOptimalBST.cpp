//最优二叉查找树，利用动态规划实现。霍夫曼树。
#include<iostream>
using namespace std;
void Optimal_BST(double *p,double *q,int length,double (*e)[20],int (*root)[20])
{
	int i,j,k,r;
	double t;
	double w[20][20]={0};
	for(i=1;i<=length+1;i++)
	{
		e[i][i-1]=q[i-1];
		w[i][i-1]=q[i-1];
	}
	//i为关键字之间的长度
	for(i=1;i<=length;i++)
	{
		//从下标为j开始的关键字到下标为k的关键字
		for(j=1;j<=length-i+1;j++)
		{
			k=i+j-1;
			e[j][k]=0x7fffffff;
			w[j][k]=w[j][k-1]+p[k]+q[k];
			//选取j到k之间的某个下标的关键字作为从j到k的根，如果组成的树的期望值当前最小，则r为从j
			//到k的根节点
			for(r=j;r<=k;r++)
			{
				t=e[j][r-1]+e[r+1][k]+w[j][k];
				if(e[j][k]>t)
				{
					e[j][k]=t;
					//r即为从下标j到k的根节点
					root[j][k]=r;
				}
			}
		}
	}

}
void Construct_Optimal_BST(int (*root)[20],int i,int j,bool flag)
{
	if(flag==0)
	{
		cout<<"k"<<root[i][j]<<" 是根"<<endl;
		flag=1;
	}
	int r=root[i][j];
	//如果左子树是叶子
	if(r-1<i)
	{
		cout<<"d"<<r-1<<" is the left child of "<<"K"<<r<<endl;
	}
	//如果左子树不是叶子
	else
	{
		cout<<"k"<<root[i][r-1]<<" is the left child of "<<"K"<<r<<endl;
		Construct_Optimal_BST(root,i,r-1,1);
	}
	//如果右子树是叶子
	if(r>=j)
	{
		cout<<"d"<<j<<" is the right child of "<<"K"<<r<<endl;
	}
	//如果右子树不是叶子
	else
	{
		cout<<"k"<<root[r+1][j]<<" is the right child of "<<"K"<<r<<endl;
		Construct_Optimal_BST(root,r+1,j,1);
	}
}
int main()
{
	double p[6]={0,0.15,0.1,0.05,0.1,0.2};
	double q[6]={0.05,0.1,0.05,0.05,0.05,0.1};
	double e[20][20]={0};
	int root[20][20]={0};
	Optimal_BST(p,q,6,e,root);
	cout<<e[1][5]<<endl;
	Construct_Optimal_BST(root,1,5,0);
	return 0;
}
