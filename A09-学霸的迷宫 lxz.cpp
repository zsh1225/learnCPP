/*
A09-学霸的迷宫
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:31            测试通过:10

描述

　　学霸抢走了大家的作业，班长为了帮同学们找回作业，决定去找学霸决斗。但学霸为了不要别人打扰，住在一个城堡里，城堡外面是一个二维的格子迷宫，要进城堡必须得先通过迷宫。因为班长还有妹子要陪，磨刀不误砍柴功，他为了节约时间，从线人那里搞到了迷宫的地图，准备提前计算最短的路线。可是他现在正向妹子解释这件事情，于是就委托你帮他找一条最短的路线。 

输入

　　第一行两个整数n， m，为迷宫的行与列。
　　接下来n行，每行m个数，数之间没有间隔，为0或1中的一个。0表示这个格子可以通过，1表示不可以。假设你现在已经在迷宫坐标(1,1)的地方，即左上角，迷宫的出口在（n,m）。每次移动时只能向上下左右4个方向移动到另外一个可以通过的格子里，每次移动算一步。数据保证(1,1)，(n,m)可以通过。

输出

　　第一行一个数为需要的最少步数K。
　　第二行K个字符，每个字符∈{U,D,L,R},分别表示上下左右。如果有多条长度相同的最短路径，选择在此表示方法下字典序最小的一个。

样例输入

3 3
001
100
110

样例输出

4
RDRD

提示


输入样例2：
3 3
000
000
000
输出样例2：
4
DDRR

数据规模和约定：1<=n,m<=500。




[提交] [讨论版] 


|返回 |   | 转到页头| 

E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<queue>  
using namespace std;  
char map[500][500];   
int vis[500][500];  
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}}; 
char dic[4]={'D','L','R','U'};     
struct point
{  
    int x,y;  
    int s;    
    string s1;  
};  
int x1,x2,y1,y2,n,m;  
void bfs()
{  
    queue<point>q;  
    point p;  
    p.x = x1; 
    p.y = y1; 
    p.s = 0;
    p.s1="";  
    vis[x1][y1]=1;  
    q.push(p);  
    while(!q.empty())
    {  
        point p=q.front();  
        if(p.x==x2&&p.y==y2)
        {  
            if(p.s==0)
            {  
                  
            }   
            printf("%d\n",p.s);  
            cout<<p.s1<<endl;  
        }  
        point v;  
        for(int i=0 ;i<4;i++)
        {  
            v.x=p.x+dir[i][0];  
            v.y=p.y+dir[i][1];  
            if(v.x>=0&&v.x<n&&v.y>=0&&v.y<m&&vis[v.x][v.y]==0&&map[v.x][v.y]!='1')
            {  
                vis[v.x][v.y]=1;   
                v.s=p.s +1;   
                v.s1=p.s1+dic[i];  
                q.push(v);  
            }  
        }  
        q.pop();  
    }  
}  
int main()
{  
    cin>>n>>m;  
    memset(map,'1',sizeof(map));  
    memset(vis,0,sizeof(vis));  
    for(int i=0;i<n;i++)
    {  
        for(int j=0;j<m;j++)
        {  
            cin>>map[i][j];  
        }  
    }  
    x1=0;
    y1=0;  
    x2=n-1;
    y2=m-1;   
    bfs();  
}  

