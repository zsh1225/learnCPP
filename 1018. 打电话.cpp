/*

1018. 打电话 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
某市的IC卡电话计费标准如下：首次为0.5元/3分钟(不足3分钟按3分钟计费)，之后是0.2元/1分钟，不足一分钟按一分钟来算，如一个人打了6分30秒，那计费是按照7分钟来算，花费为1.3元。已知某人打一次电话花费为x元，问这个人有可能打了多长时间的电话？（精确到分钟）
输入
输入一个实数x，表示打电话的花费。
输出
输出打电话的最长时长(精确到分钟)。
样例输入

0.5

样例输出

3

数据范围限制
0<x<=100

来源/作者: CCF中学生计算机程序设计入门篇练习3.5.1

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/ 

#include<bits/stdc++.h>
using namespace std;
int main ()
{
	double a;
	cin>>a;
	if(a<=0.5) cout<<3;
	else cout<<3+ceil((a-0.5)/0.2);
	return 0;
} 
