/*描述

给出N 个1到30000间无序数正整数，其中1≤N≤10000，同一个正整数可能会出现多次，出现次数最多的整数称为众数。求出它的众数及它出现的次数。 

输入

第一行是正整数的个数N，第二行开始为N个正整数。

输出

有若干行，每行两个数，第1个是众数，第2个是众数出现的次数。(两个数之间空两个空格)

样例输入

12
2 4 2 3 2 5 3 7 2 3 4 3

样例输出

2  4
3  4

题目来源

ntNOI.cn

*/

#include<iostream>
using namespace std;
int main()
{
	int q,w,a[30000]={0},max=0;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>w;
		a[w]++;
	}
	for(int i=1;i<=30000;i++){
		if(a[i]>max) max=a[i];
	}
	for(int i=1;i<=30000;i++){
		if(a[i]==max) cout<<i<<"  "<<a[i]<<endl;
	}
	return 0;
}
