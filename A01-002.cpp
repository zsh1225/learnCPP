#include<iostream>
using namespace std;
int main()
{
	short b[3];
	int a;
	cin>>a;
	for(int i=0;i<3;i++)
	{
		b[i]=a%10;
		a/=10;
	}
	cout<<"bai="<<b[2]<<endl<<"shi="<<b[1]<<endl<<"ge="<<b[0];
	return 0;
} 
