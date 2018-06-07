/*描述

军方截获的信息由n（n<=30000）个数字组成，因为是敌国的高端秘密，所以一时不能破获。最原始的想法就是对这n个数进行小到大排序，每个数都对应一个序号，然后对第i个是什么数感兴趣，现在要求编程完成。

输入

第一行n，接着是n个截获的数字，接着一行是数字k，接着是k行要输出数的序号。

输出

k行序号对应的数字。

样例输入

5
121 1 126 123 7
3
2
4
3

样例输出

提示

7
123
121

题目来源

ntNOI.cn
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[30001],n,k,w[30001];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=1;i<=k;i++){
		cout<<a[w[i]]<<endl;
	}
	return 0;
}













