/*

1013. 识别三角形 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
输入三个正整数，判断能否构成三角形的三边，如果不能，输出“NO”。如果能构成三角形，判断构成什么三角形？按等边、直角、一般三角形分类，依次输出对应的三角形类型“Equilateral”、“Right”、“General”。
输入
输入一行三个用空格隔开的正整数a,b,c，表示三角形的三条边长。
输出
输出对应三角形的类型，如果不能构成三角形，输出“NO”，如果是等边三角形输出“Equilateral”，如果是直角三角形输出“Right”，其他三角形则输出“General”。
样例输入

3 4 5

样例输出

Right

数据范围限制
1<=a,b,c<=1000

来源/作者: CCF中学生计算机程序设计入门篇练习3.3.2

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b<c||a+c<b||b+c<a) cout<<"NO";
	else if(a==b&&b==c) cout<<"Equilateral";
	else if(pow(a,2)+pow(b,2)==pow(c,2)||pow(a,2)+pow(c,2)==pow(b,2)||pow(c,2)+pow(b,2)==pow(a,2))
	cout<<"Right";
	else cout<<"General";
	return 0;
	
}








