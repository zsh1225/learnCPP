#include<iostream>
using namespace std;
int main()
{
	int a;
	int b=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		if(a%i==0) b+=i;
    }
	cout<<b;
	return 0;
}

