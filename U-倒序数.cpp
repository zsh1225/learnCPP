#include<iostream>
using namespace std;
void f(long long);
int main()
{
    long long a;
    cin>>a;
    f(a);
    return 0;
}

void f(long long a)
{
    int x;
    x=a%10;
    a/=10;
    cout<<x;
    if(a!=0) f(a);
}
