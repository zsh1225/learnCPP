/*

1015. 星期几 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
输入数字1~7的表示星期一至星期日，输出对应的星期几的英文名称。
如果是1，输出Monday;
如果是2，输出Tuesday;
如果是3，输出Wednesday;
如果是4，输出Thursday;
如果是5，输出Friday;
如果是6，输出Saturday;
如果是7，输出Sunday;
输入
输入一个数字
输出
输出对应的英文名称
样例输入

1

样例输出

Monday

数据范围限制

来源/作者: CCF中学生计算机程序设计入门篇练习3.4.2

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
	switch(a){
		case 1:cout<<"Monday";break;
		case 2:cout<<"Tuesday";break;
		case 3:cout<<"Wednesday";break;
		case 4:cout<<"Thursday";break;
		case 5:cout<<"Friday";break;
		case 6:cout<<"Saturday";break;
		case 7:cout<<"Sunday";break;
	}
	return 0;
}
