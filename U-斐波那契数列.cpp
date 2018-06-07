#include<iostream>
using namespace std;
int f(int);
int main()
{
    int a;
    cin>>a;
    cout<<f(a);
    return 0;
}

int f(int a)
{
    if(a==1) return 0;
    else if(a==2) return 1;
    else return f(a-1)+f(a-2);
}
