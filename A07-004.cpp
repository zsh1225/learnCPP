#include<iostream>
using namespace std;
int ss(int a);

int main()
{
    int a;
    cin>>a;
    cout<<ss(1);
    for(int i=a/2; i>=1; i--)
        if(ss(i)&&ss(a-i))
        {
            cout<<i*(a-i);
            break;
        }
    return 0;
}


int ss(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0) return 0;
    return 1;
}
