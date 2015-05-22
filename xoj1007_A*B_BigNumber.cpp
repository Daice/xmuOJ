/*
   123  i
 * 123  j 
 _______
   369
  246
 123
_______
  [4][3][2][1][0]---->>i+j 的值
*/

#include<iostream>
#include<cstdio>
#include<cstring> 
#define N 20000
using namespace std;
string rev(string temp) //反转函数
{
   int len=temp.length();
   char t;
   for(int i=0,j=len-1;i<j;i++,j--)
   { t=temp[i];temp[i]=temp[j];temp[j]=t;}
   return temp;
}
string  mult(string a,string b)
{
    int i,j,flag,t,k;
    string ans="";
     char c[N];
     a=rev(a);
     b=rev(b);
     memset(c,'0',sizeof(c));//初始化为'0',ASCII为48
  for(i=0;i<a.length();i++)
  {
        flag=0;
     for(j=0;j<b.length();j++)
     {
        t=c[i+j]-48 +(a[i]-48)*(b[j]-48)+flag;
        c[i+j]=t%10+48;
        flag=t/10;
     }
     while(flag)
     {
        t = c[i+j] - 48 + flag;  
        c[i+j]=t%10+48;
        flag=t/10;
     }
  }
    k=N-1;
  while(c[k]=='0'&&k>0)k--;
   for(i=k;i>=0;i--)
       ans+=c[i];
   if(ans[0]=='0')return "0";
   return ans;
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
     cout<<mult(a,b)<<endl;
    }
return 0;
}
