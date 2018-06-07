#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c,q,d,e;
	cin>>a>>b>>c;
	q=b*b-4*a*c;
	if(q>0){
		d=(b*(-1)+sqrt(q))/(2*a);
		e=(b*(-1)-sqrt(q))/(2*a);
		if(d>e){
			q=d;
			d=e;
			e=q;
		}
		cout<<"x1=";
		printf("%12.4lf",d);
		cout<<",x2=";
		printf("%12.4lf",e);
	}
	else if(q==0){
		cout<<"x1=x2=";
		printf("%12.4lf",b*(-1)/(2*a));
	}
	else cout<<"NO SOLUTION";
	return 0;
}
