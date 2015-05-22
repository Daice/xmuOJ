#include <iostream>
#include <queue>
#include<cstring>
#include<cstdio>
using namespace std;

class mycomparison
{
public:
  bool operator() (const int& lhs, const int&rhs) const
  {
    return (lhs > rhs);//使得从小到大排序，队列头为最小元素，优选权队列默认队列头最大
  }
};

int main(){
	char s[500];
	int count[200] = {0};//count[i]记录ASCII码为i的字符的个数
	int i, sum, len;
	priority_queue<int, vector<int>, mycomparison> pq;
	//while(cin>>s){
	//	if(!strcmp(s,"END")){
	//		break;
	//	}
		cin>>s;
		len = strlen(s);
		for(i = 0; i < len; i++){
			count[s[i]]++;
		} 
		sum = 0;
		for(i = 0;i < 200; i++){
			if(count[i]){
				pq.push(count[i]);
				count[i] = 0;
			}
		}
		while(pq.size() > 1){
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			sum += a + b;//其实就是把越小的频率反复多加几次，越大的频率少加几次
			pq.push(a + b);
		}
		if(!sum){
			sum = len;//此时pq中只有一个元素
		}
		while(!pq.empty()){
			pq.pop();
		}
		printf("%d\n",sum);//注意精度设置
	//}
	return 0;
}
