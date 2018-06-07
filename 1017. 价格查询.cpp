/*

1017. 价格查询 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
编程实现以下功能：查询水果的单价。有4种水果，苹果(apples)、梨(pears)、桔子(oranges)和葡萄(grapes)，单价分别是3.00元/公斤，2.50元/公斤，4.10元/公斤和10.20元/公斤。
运行程序后，首先在屏幕上显示以下菜单(编号和选项)（见样例）。
当用户输入编号1～4，显示相应水果的单价(保留1位小数)；输入0，退出查询；输入其他编号，显示价格为0。
输入
输入一个整数。
输出
输出对应的结果。
样例输入

3

样例输出

[1] apples
[2] pears
[3] oranges
[4] grapes
[0] Exit
price=4.1

数据范围限制

来源/作者: CCF中学生计算机程序设计入门篇练习3.4.4

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/ 

#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a;
	cout<<"[1] apples"<<endl
	<<"[2] pears"<<endl
	<<"[3] oranges"<<endl
	<<"[4] grapes"<<endl
	<<"[0] Exit"<<endl;
	cin>>a;
	if(a==0);
	else if(a==1) cout<<"price=3.0";
	else if(a==2) cout<<"price=2.5";
	else if(a==3) cout<<"price=4.1";
	else if(a==4) cout<<"price=10.2";
	else cout<<"price=0";
	return 0;
} 
