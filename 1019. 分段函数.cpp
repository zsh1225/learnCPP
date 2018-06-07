/*

1019. 分段函数 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
编写程序，计算下列分段函数y=f(x)的值（输入数据为浮点数，输出保留小数点后三位）。
输入
输入x。
输出
输出f(x)的值，答案保留三位小数。
样例输入

1

样例输出

3.500

数据范围限制
0<=x<20

来源/作者: CCF中学生计算机程序设计入门篇练习3.5.2

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	float a;
	cin>>a;
	if(a<5) cout<<fixed<<setprecision(3)<<a+2.5;
	else if(a<10) cout<<fixed<<setprecision(3)<<2-1.5*(a-3)*(a-3);
	else cout<<fixed<<setprecision(3)<<a/2-1.5;
	return 0;
	
}
