/*

1016. 计算天数 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
输入年份与月份，求该月共有多少天。
输入
输入两个空格隔开的正整数year和month，分别表示年份和月份
输出
输出对应year这一年month这个月的天数。
样例输入

2000 2

样例输出

29

数据范围限制
1000<=year<=3000,1<=month<=12

来源/作者: CCF中学生计算机程序设计入门篇练习3.4.3

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
	if(a%400==0) a=1;
	else if(a%100==0) a=0;
	else if(a%4==0) a=1;
	else a=0;
	switch(b)
	{
		case 1:cout<<31;break;
		case 2:cout<<28+a;break;
		case 3:cout<<31;break;
		case 4:cout<<30;break;
		case 5:cout<<31;break;
		case 6:cout<<30;break;
		case 7:cout<<31;break;
		case 8:cout<<31;break;
		case 9:cout<<30;break;
		case 10:cout<<31;break;
		case 11:cout<<30;break;
		case 12:cout<<31;break;
		
	}
	return 0;
}
