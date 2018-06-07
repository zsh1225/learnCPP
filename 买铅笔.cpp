/*
	Name: ÂòÇ¦±Ê 
	Copyright: 
	Author: 
	Date: 01-04-17 13:08
	Description: 
*/

#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,q=999999999;
	cin>>n;
	for(int s=0;s<3;s++) {
	cin>>a>>b;
	c=n/a;
	if(n%a!=0) c++;
	if(c*b<q) q=c*b;}
	cout<<q;
}
