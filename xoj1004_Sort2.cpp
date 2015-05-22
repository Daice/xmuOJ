#include<iostream>
#include<algorithm>
using namespace std;

bool com(int a,int b)
{
	return a<b;
}
int main()
{
	int n,*a;
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,com);
	for(int i=0;i<n-1;i++)
		cout<<a[i]<<" ";
	cout<<a[n-1]<<endl;
	return 0;
}
