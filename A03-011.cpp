//把整数3025从中剪开分为30和25两个数，此时再将这两数之和平方，(30+25)2=3025计算结果又等于原数。求所有符合这样条件的四位数。 (同 1023 A03-009)
#include<iostream>
using namespace std;
int main()
{
	int a;
	for(int i=32;i<=99;i++){
		a=i*i;
		if(((a/100)+(a%100))*((a/100)+(a%100))==a) cout<<a<<endl;
	}
	return 0;
} 
