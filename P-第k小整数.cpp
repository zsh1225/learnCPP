/*描述

现有n个正整数，n≤10000，要求出这n个正整数中的第k个最小整数（相同大小的整数只计算一次），k≤1000，正整数均小于30000。

输入

第一行为n和k;
第二行开始为n个正整数的值，整数间用空格隔开。

输出

第k个最小整数的值；若无解，则输出“NO RESULT”。

样例输入

10 3
1 3 3 7 2 5 1 2 4 6

样例输出

3

题目来源

ntNOI.cn
*/ 

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,a[10001],b[10001],w=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,(a+1)+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) {
		w++;
		b[w]=a[i];
		}
	}
	if(w<k) cout<<"NO RESULT";
	else cout<<b[w];
	return 0;
}




