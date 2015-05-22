#include<cstdlib>
#include<iostream>
#define max 1024 
int array[max][max];
int au =1;
using namespace std ;
int inter(int n )
{
    if(n==1)
    return 2 ;
    else return 2*inter(n-1);
}
void chessboard(int tr , int ts , int m , int n , int size)
{
//tr是行号，ts是列号，m,n分别是缺陷的行列号，size是这个盘的规格大小
     if(size==1) return ;
     else size = size /2 ;
     int flag=au++ ;
          
     if(m<tr+size&&n<ts+size) //左上角 
     chessboard(tr,ts,m,n,size) ;
     else 
     {
          array[tr+size-1][ts+size-1]=flag ;
          chessboard(tr,ts,tr+size-1,ts+size-1,size);
     }
     
     if(m<tr+size&&n>=ts+size) //右上角 
     chessboard(tr,ts+size,m,n,size);
     else 
     {
          array[tr+size-1][ts+size]=flag ;
          chessboard(tr,ts+size,tr+size-1,ts+size,size);
     }
     
     if(m>=tr+size&&n<ts+size) //左下角
     chessboard(tr+size,ts,m,n,size);
     else 
     {
          array[tr+size][ts+size-1]=flag ;
          chessboard(tr+size,ts,tr+size,ts+size-1,size);
     }
     if(m>=tr+size&&n>=ts+size)
     chessboard(tr+size,ts+size,m,n,size);
     else 
     {
          array[tr+size][ts+size]=flag ;
          chessboard(tr+size,ts+size,tr+size,ts+size,size);
          }
}
int main()
{
    int number ;
    int i , j ;
    cin>>number ;
    cin>>i >>j ;
    int n = inter(number);
    chessboard(0,0,i-1,j-1,n);
    //array[i-1][j-1]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         {
                    cout<<array[i][j];
                    if(j==n-1)
                    cout<<endl;
                    else cout<<" ";
         }
    return 0 ;
}
