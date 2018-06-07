#include<iostream>
using namespace std;
void f(int);
int main()
{
    int a;
    cin>>a;
    f(a);
    return 0;
}

void f(int a)
{
    if(a<8) cout<<a;
    else
    {
        int x;
        x=a%8;
        a/=8;
        if(a==0) cout<<1;

        else
        {
            f(a);
            cout<<x;
        }
    }
}
