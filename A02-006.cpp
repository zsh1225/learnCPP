//输入年份year、月份month，输出该月的天数day。 
#include<iostream>
using namespace std;
bool y(short a);
int main()
{
	short a,b;
	cin>>a>>b;
	if(b==1||b==3||b==5||b==7||b==8||b==10||b==12) cout<<"31";
	else if(b==2){
		if(y(a)==0) cout<<"28";
		else cout<<"29";
	}
	else cout<<"30";
	return 0;
} 
bool y(short a)
{
	if(a%400==0) return 1;
	else if(a%100==0) return 0;
	else if(a%4==0) return 1;
	else return 0;
}
