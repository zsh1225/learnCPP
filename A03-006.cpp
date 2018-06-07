/*判断输入的自然数a（>=1）是否为素数*/
#include<iostream>
using namespace std;
const char* ss(long long n);
int main()
{
	long long a;
	cin>>a;
    cout<<ss(a); 
	return 0;
}
const char* ss(long long n)

{
	if(n==1) return "FALSE";
    for(int i=2; i*i<=n; i++)
        if(n%i==0) return "FALSE";
    return "TRUE";
}
