//�������year���ж�year�Ƿ�Ϊ���ꡣ
#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%400==0) cout<<"SHI";
	else if(a%100==0) cout<<"FOU";
	else if(a%4==0) cout<<"SHI";
	else cout<<"FOU";
	return 0;
} 
