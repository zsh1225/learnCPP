//从键盘输入n(n<=20)个整数，将它们按照从小到大的顺序输出。 
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
