#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double a,b;
	char c;
	cin>>a>>b>>c;
	switch(c){
		case '+':printf("%12.4lf",a);cout<<'+';printf("%12.4lf",b);cout<<'=';printf("%12.4lf",a+b);break;
		case '-':printf("%12.4lf",a);cout<<'-';printf("%12.4lf",b);cout<<'=';printf("%12.4lf",a-b);break;
		case '*':printf("%12.4lf",a);cout<<'*';printf("%12.4lf",b);cout<<'=';printf("%12.4lf",a*b);break;
		case '/':if(b==0) {cout<<"ERROR";break;} else printf("%12.4lf",a);cout<<'/';printf("%12.4lf",b);cout<<'=';printf("%12.4lf",a/b);break;
	}
	return 0;
}
