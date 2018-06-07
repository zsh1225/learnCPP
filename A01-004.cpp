#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;
int roun(double x);
int main()
{
	int b;
	double a,c=0;
	cin>>a;
	printf("%12.4lf\n",fabs(a));
	printf("%12.4lf\n",a*a);
	printf("%12.4lf\n",sqrt(abs(a)));
	b=a;
	c=b;
	printf("%12.4lf\n",c);
	printf("%12.4lf\n",a-c);
	cout<<roun(a)<<endl;
	cout<<b;
	return 0;
} 
int roun(double x)
{return (x>0.0)? int(x+0.5):int(x -0.5);} 
