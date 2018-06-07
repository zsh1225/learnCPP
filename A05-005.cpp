/*描述

判断一个整数是否为回文数（正过来读与反过来读相同）。

输入

输入整数a(不超过9位)

输出

若是回文数，输出“YES”，否则输出“NO”

样例输入

1234321

样例输出

YES*/ 

#include<iostream>
#include<string>
using namespace std;
int main()
{
	bool w=1;
	string q;
	cin>>q;
	for(int i=q.size()-1,j=0;j<=i;i--,j++){
		if(q[j]!=q[i]) w=0;
	}
	if(w==0) cout<<"NO";
	else cout<<"YES";
	return 0;
} 
