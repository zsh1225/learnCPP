//���n(n<=10)�������и���ƽ��������Щ������ 
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
