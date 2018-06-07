#include<iostream>
using namespace std;
int k=0,n;
void s(int,char,char,char);
int main()
{
    int n;
    cin>>n;
    s(n,'a','c','b');
    return 0;
}

void s(int n,char a,char c,char b)
{
    if(n==0) return;
    s(n-1,a,b,c);
    k++;
    cout<<k<<":from "<<a<<"-->"<<c<<endl;
    s(n-1,b,c,a);
}
