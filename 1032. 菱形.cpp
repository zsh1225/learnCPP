/*

1032. 菱形 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
输入一个正整数n，输出用1至(2n-1)的数字组成的菱形。
输入
输入正整数n。
输出
输出对应的菱形(见样例)。
样例输入

3

样例输出

  1 
 123
12345
 123
  1

数据范围限制
1<=n<=10

来源/作者: CCF中学生计算机程序设计入门篇练习4.4.3

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
			cout<<j;
		}
		cout<<endl;
	}
	for(int i=a-1;i>=1;i--)
	{
		cout<<setw(a-i+1);
		for(int j=1;j<=i*2-1;j++)
		{
			cout<<j;
		}
		cout<<endl;
	}
	return 0;
} 
