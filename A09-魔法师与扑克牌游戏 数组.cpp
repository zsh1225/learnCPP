/*
A09-魔法师与扑克牌游戏
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:10            测试通过:3

描述

魔法师在玩一种扑克牌游戏，n张扑克分别记上1,2，...，n。他打开第一张是1，把它放在一边，然后把最上面的两张一张一张地依次移到最后，打开上面一张刚好是2,再放在一边；然后把上面的3张一张一张移到最后，打开上面一张正好是3，再放到一边；......如此重复下去，直到最后一张是n，放在一边，这时他发现，放在一边的扑克刚好是1，2，...，n这样排列的。请编程输出这些扑克原来是怎么排列的。

输入

一行一行正整数n。

输出

一行n个正整数，表示这些扑克牌原来的排列顺序，每两个数之间有一个空格。

样例输入

5

样例输出

1 4 5 2 3

提示

【输入样例2】
9
【输入样例2】
1 8 6 2 9 4 5 3 7
【数据范围】
对于70%的数据：n≤100。
【注意】输出最后一个数后面，没有空格。
对于100%的数据：n≤10000。

[提交] [讨论版]

|返回 |   | 转到页头|
E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/

#include<cstdio>
#include<queue>
using namespace std;
short q[100000000];
int main()
{
    int n,front=1,rear=1;
    scanf("%d",&n);
    for(int i=n;i>1;i--){
        q[rear++]=i;
        for(int j=1;j<=i;j++){
            q[rear++]=q[front++];
        }
    }
    q[rear++]=1;
    printf("%d",q[rear-1]);
    for(int i=rear-2;i>=front;i--)
       printf(" %d",q[i]);
    printf("\n");
    return 0;
}  
