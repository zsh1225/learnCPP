/*描述

子数整数。对于一个五位数a1a2a3a4a5，可将其拆分为三个子数：
 sub1=a1a2a3
 sub2=a2a3a4
 sub3=a3a4a5
    例如，五位数20207可以拆分成
 sub1=202
 sub2=020（=20）
 sub3=207
    现在给定一个正整数K，要求你编程求出10000到30000之间所有满足下述条件的五位数，条件是这些五位数的三个子数sub1，sub2，sub3都可被K整除。

输入

输入正整数K（0<K<1000）

输出

每行输出一个满足条件的五位数，要求从小到大输出。不得重复输出或遗漏。如果无解，则输出“No”。

样例输入

15

样例输出

22555
25555
28555
30000

题目来源

www.ntnoi.cn
*/ 

#include<iostream>
using namespace std;
int a1,a2,a3,a4,a5;
int chafen(int);
int main()
{
/*	bool a=1;
	int K;
	cin>>K;
	for(int i=10000;i<=99999;i++){
		if((i/100)%K==0&&((i/10)%1000)%K==0&&(i%1000)%K==0){
			cout<<i<<endl;
			a=0;
		}
	}
	if(a) cout<<"No";
*/
chafen(10000);
cout<<a1<<endl;
cout<<a2<<endl;
cout<<a3<<endl;
cout<<a4<<endl;
cout<<a5<<endl;
	return 0;
} 

int chafen(int a)
{
	a1=a/10000;
	a2=(a/1000)%10;
	a3=a/100-a/1000*10;
	a4=a/10-a/100*10;
	a5=a%10;
}



