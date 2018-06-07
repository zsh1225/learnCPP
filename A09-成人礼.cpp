/*
A09-成人礼
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:11            测试通过:7

描述

   昨天lzz成人礼，他邀请了n个人来参加。这n个人陆陆续续来到，lzz的成人礼现场有一张大长椅，每当有一个人来lzz就会让他从长椅的左边或右边进去坐下。由于来的人太多，lzz已经忙坏了，以至于当hxy来到之后问他：“现在长椅上坐着的人从左往右依次是谁？”时，他也无法立即回答出来。现在请你编一个程序来帮他回答这个问题。

输入

   第一行有一个整数n。1<=n<=20000。
   后面n行有一个数字a和字符串Name，当a=0表示这个人是从左边进入长椅的，当a=1时表示这个人是从右边进入长椅的。Name表示第i个到来的人的名字。

输出

   共n行，依次表示长椅上从左到右的人的名字。
   注：题目中的hxy不被认为是n个人当中的一个，且她是在n个人到来之后才来的。

样例输入

10
0 LZZ
0 HSY
0 TSW
1 LHS
1 WKA
0 LWJ
1 HT
0 ZZB
1 DYL
0 ZJX

样例输出

ZJX
ZZB
LWJ
TSW
HSY
LZZ
LHS
WKA
HT
DYL

[提交] [讨论版]

|返回 |   | 转到页头|
E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string l[20010],r[20010];
	int n,x=1,y=1,h;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h;
		if(h==0)
        {
            cin>>l[x];
            x++;
        }

		else if(h==1)
        {
            cin>>r[y];
            y++;
        }

	}
	for(int i=x-1;i>=1;i--)
	cout<<l[i]<<endl;
	for(int i=1;i<y;i++)
	cout<<r[i]<<endl;
	cout<<r[y]; 
	return 0;
}
