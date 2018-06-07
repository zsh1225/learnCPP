#include<iostream>
using namespace std;
int s[10001]={0};
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
    int q=1;
    if(a==1) return 1;
    for(int i=1;i<=a/2;i++)
    {
        if(s[i]==0) s[i]=f(i);
        q+=s[i];
    }
    return q;
}
