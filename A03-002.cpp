#include<iostream>
using namespace std;
int main()
{
	int a,i=1;
	long long b=0;
	cin>>a;
	for(i;i<=a;i++){
		if(b+i>=a) break;
		b+=i;
	}
	cout<<i-1;
	return 0;
}
