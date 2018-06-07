/*

1007. 计算余数 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
计算两个双精度浮点数a和b相除的余数，a和b都是正数。这里余数（r）的定义是：a = k * b + r，其中 k是整数， 0 <= r < b。
输入
一行两个空格隔开的数a和b。
输出
输出a除以b的余数(答案保留两位小数)。
样例输入

3 2

样例输出

1.00

数据范围限制

来源/作者: CCF中学生计算机程序设计入门篇练习2.6.4

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b;
	cin>>a>>b; 
	cout<<fixed<<setprecision(2)<<a-floor(a/b)*b;
}
