#include<iostream>
using namespace std;
int main()
{
	int b[3];
	char a;
	cin>>a;
	a--;
	b[0]=a;
	cout<<a<<' ';
	a++;
	b[1]=a;
	cout<<a<<' ';
	a++;
	b[2]=a;
	cout<<a<<endl;
	cout<<b[0]<<' '<<b[1]<<' '<<b[2];
	return 0;
} 
