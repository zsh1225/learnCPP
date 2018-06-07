#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[6];
	for(int i=1;i<=5;i++)
	{
		a[i]=32;
	}
	for(int i=5;i>=1;i--)
	{
		for(int j=1;j<=5;j++)
		{
			if(i!=j)
			{
				a[j]/=2;
				a[i]+=a[j];
			}
		}
	}
	for(int i=1;i<=5;i++)
	{
		cout<<setw(4)<<a[i];
	}
	return 0;
} 
