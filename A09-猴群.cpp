/*
A09-猴群
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:23            测试通过:11

描述

给出一个由数字0~9组成的矩形，其中数字0代表树，1~9代表猴子，凡是由0或矩形边围起来的区域表示一群猴子在这一带。编程求矩形中有多少群猴子。

输入

第一个两个正整数，表示矩形的行数m和列数n，1,≤m ,n≤100；
下面为一个m×n的数字矩形。

输出

一行一个数，表示猴群的数目。

样例输入

4 10
0234500067
1034560500
2045600671
0000000089

样例输出

4

[提交] [讨论版]

|返回 |   | 转到页头|
E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>
using namespace std;
char s[200][200];
void hq(int a,int b)
{ 
	if(s[a][b]=='0') return ;
	s[a][b]='0';
	hq(a,b+1);
	hq(a+1,b);
	hq(a,b-1);
	hq(a-1,b);
	return ;
} 
int main()
{
	
	int a,b,num=0;
	cin>>a>>b;
	for(int i=0;i<=a+1;i++)
	{
		for(int j=0;j<=b+1;j++)
		{
			s[i][j]='0';
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(s[i][j]!='0')
			{
				num++;
				hq(i,j);
			}
		}
	}
	cout<<num;
	return 0;
}
