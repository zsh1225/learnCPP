/*

1021. 发放奖金 (Standard IO)
时间限制: 1000 ms  空间限制: 262144 KB  具体限制 
题目描述
企业发放的奖金根据利润分段计算提成。当利润I低于或等于10万元的，奖金可提10%；利润高于10万元，低于20万元，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；20万到40万的，低于20万的部分仍按上述办法提成（下同）。高于20万元的部分按5%提成；40万到60万时，高于40万的部分按3%提成；60万到100万时，高于60万的部分按1.5%提成；I>=100万元时，超过100万元的部分按1%提成。输入当月利润I，求应发奖金总数(单位为元)？（输出保留小数点后三位）
输入
输入实数I，表示利润。
输出
输出奖金数，答案保留三位小数。
样例输入

100000

样例输出

10000.000

数据范围限制
0<I<=1,000,000

来源/作者: CCF中学生计算机程序设计入门篇练习3.5.4

版权所有 ? 中国计算机学会
中国计算机学会拥有本题目（含题面、数据）的版权

所有管理员添加的题目 使用此版权/授权形式

*/ 

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    double a;
    cin>>a;
    if(a<=100000) cout<<fixed<<setprecision(3)<<a*0.1;
    else if(a<=200000) cout<<fixed<<setprecision(3)<<10000+(a-100000)*0.075;
    else if(a<=400000) cout<<fixed<<setprecision(3)<<10000+7500+(a-200000)*0.05;
    else if(a<=600000) cout<<fixed<<setprecision(3)<<10000+7500+10000+(a-400000)*0.03;
	else if(a<=1000000) cout<<fixed<<setprecision(3)<<10000+7500+10000+6000+(a-600000)*0.015;
	else cout<<fixed<<setprecision(3)<<10000+7500+10000+6000+6000+(a-1000000)*0.01;
	return 0;
} 
