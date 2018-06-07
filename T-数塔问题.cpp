/*描述

设有一个三角形的数塔，顶点为根结点，每个结点有一个整数值。从顶点出发，可以向左走或向右走，如图所示：(http://online.ntnoi.cn:8080/acmhome/judge/images/1114.jpg)


若要求从根结点开始，请找出一条路径，使路径之和最大，只要输出路径的和。

输入

第一行为n(n<10)，表示数塔的层数
从第2行至n+1行，每行有若干个数据，表示数塔中的数值。

输出

输出路径和最大的路径值。

样例输入

5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11

样例输出

86*/ 

#include<iostream>
using namespace std;
int main()
{
	int a[11][11],q;
	cin>>q;
	for(int i=1;i<=q;i++)
	    for(int j=1;j<=i;j++) cin>>a[i][j];
	for(int i=q-1;i>=1;i--)
	    for(int j=1;j<=q;j++){
			a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
		} 
	cout<<a[1][1];
	return 0;
} 
