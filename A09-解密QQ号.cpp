/*
A09-解密QQ号
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:39            测试通过:23

描述

    冬令营期间，你认识一位新朋友（一个小美女哦~），你向她询问QQ号，她当然不会直接告诉你啦，而是给了一串加密过的数字，同时也告诉了解密规则。
    规则是这样的：首先将第1个数删除，紧接着将第2个数放到这串数的末尾，再将第3个数删除并将第4个数再放到这串数的末尾，再将第5个数删除……直到剩下最后一个数，将最后一个数也删除。按照刚才删除的顺序，把这些删除的数连在一起就是她的QQ啦。 

输入

    两行。第一行包含一个整数n（n <=100），表示加密串中数字的个数。第二行包含一行数字，代表一串加密过的数字，中间用一个空格间隔。

输出

    一行数字，代表解密过后的QQ号，每个数字后面都有一个空格。

样例输入

9
6 3 1 7 5 8 9 2 4

样例输出

6 1 5 9 4 7 2 8 3



[提交] [讨论版] 


|返回 |   | 转到页头| 

E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>
#include<queue>
using namespace std;
const int MAXN=100+10;
int main()
{
    int w,x;
    queue<int> q;
    cin>>w;
    for(int i=1;i<=w;i++){
        cin>>x;
        q.push(x);
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
} 

