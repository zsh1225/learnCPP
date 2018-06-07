#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	float a,b,c;
	cin>>a>>b>>c;
	cout<<"min="<<min(a,min(b,c));
	return 0;
}
