/*

1014. 写评语 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
输入某学生成绩score，根据成绩好坏输出相应评语。如果成绩在大于等于90，输出“Excellent”；如果成绩在大于等于80分且小于90分，输出“Good”；如果成绩大于等于60分且小于80分，输出“Pass”；成绩小于60分，输出“Fail”。
输入
输入一个整数score，表示学生的成绩
输出
输出对应的评语。
样例输入

65

样例输出

Pass

数据范围限制
0<=score<=100

来源/作者: CCF中学生计算机程序设计入门篇练习3.3.3

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a>=90) cout<<"Excellent";
	else if(a>=80) cout<<"Good";
	else if(a>=60) cout<<"Pass";
	else cout<<"Fail";
	return 0;
}



