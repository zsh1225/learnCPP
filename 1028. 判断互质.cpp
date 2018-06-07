/*

1028. 判断互质 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
输入两个正整数m和n，判断m和n是否互质（即最大公约数为1），是则输出Yes，否则输出No。
 
输入
输入两个整数m和n，中间用空格隔开。
输出
如互质输出Yes，否则输出No。
样例输入

36 56

样例输出

No

数据范围限制
1<=n,m<2^31

来源/作者: CCF中学生计算机程序设计入门篇练习4.2.3

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b) swap(a,b);
	for(int i=2;i<=a;i++)
	{
		if(a%i==0&&b%i==0) {
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
