//输出n(n<=10)个整数中高于平均数的那些整数。 
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,a[10];
	float b=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b+=a[i];
	}
	b/=n;
	for(int i=0;i<n;i++){
		if(a[i]>b) cout<<setw(6)<<a[i];
	}
}
