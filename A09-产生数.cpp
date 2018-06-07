/*
A09-产生数
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:26            测试通过:23

描述

给出一个整数n（n<=2000）和k个变换规则（k≤15）。规则：
① 1个数字可以变换成另1个数字；
② 规则中，右边的数字不能为零。
例如：n=234，k=2规则为
2 → 5
3 → 6
上面的整数234经过变换后可能产生出的整数为（包括原数）234，534，264，564共4种不同的产生数。
求经过任意次的变换（0次或多次），能产生出多少个不同的整数。仅要求输出不同整数个数。 

输入

n
k
x1 y1
x2 y2
… …
xn yn

输出

格式为一个整数（满足条件的整数个数）。

样例输入

234
2
2 5
3 6

样例输出

4

提示


 




[提交] [讨论版] 


|返回 |   | 转到页头| 

E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>
#include<queue>
using namespace std;
const int maxn=10001;
const int maxm=16;
int n,k,head,x,y,mod,tmp;
int exist[maxn],que[maxn],a[maxm],b[maxm];
int main()
{
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a[i]>>b[i];
	}
	exist[n]=1;que[1]=n;head=1;
	for(int tail=0;head>=tail;)
	{
		x=que[++tail];
		y=x;
		mod=1;
		while(x>0)
		{
			tmp=x%10;
			x/=10;
			for(int i=0;i<k;i++)
			{
				if(a[i]==tmp)
				{
					int p=y+(b[i]-tmp)*mod;
					if(exist[p]==0){
						exist[p]=1;que[++head]=p;
					}
				}
				
			}
			mod*=10;
		}
	} 
	cout<<head<<endl;
	return 0;
}
