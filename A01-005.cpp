#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c,d;
    cin>>a>>b;
    c=exp(b*log(a));
    d=log(b)/log(a);
    printf("%12.4lf\n",c);
    printf("%12.4lf\n",d);
} 
