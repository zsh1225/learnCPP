//�Ӽ�������n(n<=20)�������������ǰ��մ�С�����˳������� 
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[20];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<setw(6)<<a[i];
	} 
}
