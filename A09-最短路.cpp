/*
A09-最短路
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:6            测试通过:3

描述

给定一个包含N个点，M条边的无向图，每条边的边权均为1。
再给定K个三元组(A,B,C)，表示从A点走到B点后不能往C点走(即路径中不能出现连续三个点为ABC)。注意三元组是有序的，如可以从B点走到A点再走到C点。
现在你要在K个三元组的限制下，找出1号点到N号点的最短路径。

输入

输入第一行有三个数N,M,K，意义如题目所述。
接下来M行每行两个数A,B，表示A,B间有一条边。
再下面K行，每行三个数(A,B,C)描述一个三元组。

输出

输出一个数S表示最短路径长度。

样例输入

4 4 2
1 2
2 3
3 4
1 3
1 2 3
1 3 4

样例输出

4

提示

【数据规模】
对于40%的数据满足N<=10,M<=20,K<=5。
对于100%的数据满足N<=3000,M<=20000,K<=100000。

[提交] [讨论版]

|返回 |   | 转到页头|
E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/

#include<iostream>
#include<algorithm>
using namespace std;
int s[3010][20010],
    ss[3010]={0},
    za[100001];
/*int hq(int a,int b,int k)
{ 
	
	if(a==m&&b==n) return k;
	k++;
	if(s[a][b]==0) return 100000000;
	s[a][b]=1;
    int min=100000000,x;
    for(int i=1;i<=3000;i++)
    {
    	x
    }
	return min(a1,min(a2,min(a3,a4)));
} */
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		s[a][s[a]++]=b;
		s[b][s[b]++]=a;
	}
	for(int i=1;i<=k;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		s[a][s[a]++]=b;
		s[b][s[b]++]=a;
	}
	return 0;
}



