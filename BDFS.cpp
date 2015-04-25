#include<iostream>  
#include <queue>  
using namespace std;  
#define  MAX_NODE 12  
bool visited[MAX_NODE] ;  
int stack[ MAX_NODE] ;  
queue<int> q;  
int Matric[MAX_NODE][MAX_NODE] =  
{  
    {-1,1,1,0,0,0,0,0,0,0,0,0},  
    {1,-1,1,0,1,1,0,0,0,0,0,0},  
    {1,1,-1,1,0,0,0,0,0,0,0,0},  
    {0,0,1,-1,1,0,0,0,0,0,1,1},  
    {0,1,0,1,-1,0,0,0,0,0,0,0},  
    {0,1,0,0,0,-1,0,0,0,0,1,0},  
    {0,0,0,0,0,0,-1,1,1,1,0,0},  
    {0,0,0,0,0,0,1,-1,0,0,0,0},  
    {0,0,0,0,0,0,1,0,-1,1,1,0},  
    {0,0,0,0,0,0,1,0,1,-1,0,1},  
    {0,0,0,1,0,1,0,0,1,0,-1,0},  
    {0,0,0,1,0,0,0,0,0,1,0,-1},   
};  
void DFS( int v)  
{  
    cout << " v"<< v ;  
    int top = -1 ;  
    visited[v] = true ;  
    stack[++top] = v ;  
    while ( top != -1)  
    {  
        v = stack[top] ; 
	int i; 
        for (i = 0 ; i < MAX_NODE ; i++)  
        {  
            if (Matric[v][i] == 1 &&!visited[i])  
            {  
                cout << " v" << i ;  
                visited[i] = true ;  
                stack[ ++top ] = i ;  
                break ;  
            }  
        }  
        if( i == MAX_NODE)  
        {  
            top -- ;  
        }  
    }  
      
}  
  
  
void BFS( int v)  
{  
    int node = 0;  
    q.push(v);  
    visited[v] = true;  
    while( !q.empty())  
    {         
        node = q.front();  
        for ( int i = 0; i < MAX_NODE; i++ )  
        {  
            if ( Matric[node][i] == 1 && !visited[i])  
            {  
                visited[i] = true;  
                q.push(i);  
            }  
        }  
        cout <<" v" << node;  
        q.pop();  
    }  
      
      
}  
void Init()  
{  
      
    int i = 0;  
    for ( i = 0; i < MAX_NODE; i++)  
    {  
        visited[i] = false;  
    }  
}  
int main()  
{  
    Init();  
    DFS( 1 ) ;  
    cout << endl ;  
    Init();  
    BFS( 1 );  
    cout << endl;  
    Init();  
    DFS( 6 );  
    cout <<endl;  
    return 0 ;  
}
