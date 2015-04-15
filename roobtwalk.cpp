/*
 * 题目：
 * 一个机器人每步可以走 1 米、2 米或 3 米。
 * 编写一个动态规划算法，计算机器人走n 米，有多少种走法（考虑步骤的次序）。
 *
 *
 * 算法思路：
 * 设总路程为n米，共有s(n)种走法
 *
 * 假设初值s(0) = 1
 * 易知s(1) = 1  s(2) = 2
 * 可以求出递推式：s(n) = s(n - 1) + s(n - 2) + s(n - 3) 
 *
 * 递归求s(n)的方法：return s(n - 1) + s(n - 2) + s(n - 3);
 * 用动态规划求解：
 * 建立一个长度为3的数组，将每次运算的结果存进数组中，最后数组的和即为所求
 * 这样可以避免每次计算s(i)都要从s(0) + s(1) + s(2) 算起
 *
 * 时间复杂度：Θ(n) 
 * 空间复杂度：Θ(1)
 *
 */

#include <iostream>
using namespace std;

int robotWalk(int n)
{
	int a[3] = {1, 1, 2};

	if(n <= 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return a[1];
	}
	else if(n == 2)
	{
		return a[2];
	}
	else
	{
		int count = 0;
		int temp = 0;
		for(int i = 2; i < n; i++)
		{
			temp = a[2] + a[1] + a[0];
			a[count] = temp;
			count = (count + 1) % 3;
		}

		return temp;
	}
}

int main()
{
	int n;
	char ch = 'y';
	while(ch == 'y' || ch == 'Y')
	{
		cout<<"请输入机器人的总路程:";
		cin>>n;
		if(n < 0)
		{
			cout<<"输入错误，总路程必须大于等于0"<<endl;
		}
		cout<<"共有"<<robotWalk(n)<<"种走法"<<endl;

		cout<<endl<<"是否继续?y/n:";
		cin>>ch;
	}

	return 0;
}
