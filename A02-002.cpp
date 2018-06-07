#include<iostream>
using namespace std;
int main()
{
	float a,b,c;
	cin>>a>>b;
	c=a/(b*b*b)*100000;
	if(c<1) cout<<"Thin";
	else if(c<1.15) cout<<"Little Thin";
	else if(c<1.45) cout<<"Standard";
	else if(c<1.6) cout<<"Little Fat";
	else cout<<"Too Fat";
	return 0;
} 
