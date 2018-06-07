/*

1031. 等腰三角形 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
输入一个正整数n，输出高为n的由*组成的等腰三角形。
输入
输入一个正整数。
输出
输出高为n的由*组成的等腰三角形。
样例输入

3

样例输出

  *
 ***
*****

数据范围限制
1<=n<=20

来源/作者: CCF中学生计算机程序设计入门篇练习4.4.2

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cout<<setw(a-i+1);
		for(int j=1;j<=i*2-1;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
} 
