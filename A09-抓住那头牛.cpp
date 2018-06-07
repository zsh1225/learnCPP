/*
A09-抓住那头牛
时间限制(普通/Java):10000MS/30000MS          运行内存限制:65536KByte
总提交:29            测试通过:14

描述

农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上，农夫起始位于点N(0<=N<=100000)，牛位于点K(0<=K<=100000)。农夫有两种移动方式：
1、从X移动到X-1或X+1，每次移动花费一分钟
2、从X移动到2*X，每次移动花费一分钟
假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多少时间才能抓住牛？ 

输入

两个整数，N和K。

输出

一个整数，农夫抓到牛所要花费的最小分钟数。

样例输入

5 17

样例输出

4



[提交] [讨论版] 


|返回 |   | 转到页头| 

E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N;
int K;

int visit[100001];

struct Step
{
    int x;
    int xx;
    Step(int a,int b):x(a),xx(b){}
};

int main()
{
    cin>>N;
    cin>>K;

    memset(visit,0,sizeof(visit));

    queue<Step> p;
    p.push(Step(N,0));
    visit[N]=1;

    while(!p.empty())
    {
        Step s=p.front();
        if(s.x==K)
        {
            cout<<s.xx<<endl;
            return 0;
        }
        else
        {
            if(s.x-1>0&&visit[s.x-1]!=1)
            {
                p.push(Step(s.x-1,s.xx+1));
                visit[s.x-1]=1;
            }
            if(s.x+1<100001&&visit[s.x+1]!=1)
            {
                p.push(Step(s.x+1,s.xx+1));
                visit[s.xx+1]=1;
            }
            if(s.x*2<100001&&visit[s.x*2]!=1)
            {
                p.push(Step(s.x*2,s.xx+1));
                visit[s.x*2]=1;
            }
        }
        p.pop();
    }
    return 0;

} 



