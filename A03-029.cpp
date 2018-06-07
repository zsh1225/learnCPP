/*输入一串字符，以“.”结束。内有数字和非数字字符。如“A123X456Y7A.”，“302ATB567BC.”，
打印字符串中所有连续（指不含非数字字符）的数字所组成的整数，每个数字占一行，并统计共有多少个整数。*/
#include<iostream>
using namespace std;
int main()
{
	char a;
	int b=0;
	while(a!='.'){
		cin>>a;
		if(a-'0'>=0&&a-'0'<=9){
			b++;
			while(a-'0'>=0&&a-'0'<=9){
				cout<<a;
				cin>>a;
			}
			cout<<endl;
		}
    }
    cout<<b; 
	return 0;
}

