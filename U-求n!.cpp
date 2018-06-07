#include<iostream>
using namespace std;
long long f(int);
int main()
{
    int a;
    cin>>a;
    cout<<a<<"!="<<f(a);
    return 0;
}

long long f(int a)
{
    if(a==1) return 1;
    else return f(a-1)*a;
}

