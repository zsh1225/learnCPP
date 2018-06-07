/*
A09-取牌游戏
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:48            测试通过:27

描述

　　小明正在使用一堆共k张纸牌与n-1个朋友玩取牌游戏。其中，2≤n≤100，n≤k≤100000，k是n的倍数。纸牌中包含m=k/n张“good”和k-m张“bad”牌。小明负责发牌，他当然想自己获得所有“good”牌。
　　他的朋友怀疑他会欺骗，所有他们给出一线限制，以防小明耍诈：
　　① 游戏开始时，将最上面的牌发给小明右手的人。
　　② 每发完一张牌，他必须将接下来的p张牌（1≤p≤10）一张一张地依次移到最后，放在牌堆的底部。
　　③ 以逆时针方向，连续给每位玩家发牌。
　　小明迫切想赢，请你帮助他算出所有“good”牌放置的位置，以便他得到所有“good”牌。牌从上往下依次标注为#1，#2，#3，…

输入

    一行三个正整数n、k和p，用一个空格隔开。

输出

    m行，从顶部按升序依次输出“good”牌的位置。

样例输入

3 9 2

样例输出

3
7
8

[提交] [讨论版]

|返回 |   | 转到页头|
E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn

*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	queue<int> a;
	int n,k,p,m,x,num=0,ans[20000];
	cin>>n>>k>>p;
	m=k/n;
	for(int i=1;i<=k;i++)
	{
		a.push(i);
	}
	while(!a.empty())
	{
		for(int i=1;i<=n;i++)
		{
		    x=a.front();
		    a.pop();
		    for(int j=1;j<=p;j++)
		    {
		    	a.push(a.front());
		    	a.pop();
		    }
			
		}
		ans[num++]=x;
	}
	sort(ans,ans+num);
	for(int i=0;i<num;i++)
	cout<<ans[i]<<endl;
	return 0;
}
