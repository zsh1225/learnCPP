/*

1036. 进制转换 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
模拟将任意给定的正整数n转换成对应的二进制数的过程：对于输入的任意正整数n，输出若干行“shang:* yu:*”的形式，表示其转换过程。
输入
输入正整数n。
输出
输出其转为二进制的过程(具体见样例)。
样例输入

13

样例输出

shang:6 yu:1
shang:3 yu:0
shang:1 yu:1
shang:0 yu:1

数据范围限制
1<=n<=5000

来源/作者: CCF中学生计算机程序设计入门篇练习4.5.2

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/

#include<bits/stdc++.h>
using namespace std;
void zh(int a)
{
	int y;
	if(a==0) return;
	y=a%2;
	a/=2;
	cout<<"shang:"<<a<<" yu:"<<y<<endl;
	zh(a);
}
int main()
{
	int a;
	cin>>a;
	zh(a);
	return 0;
}
