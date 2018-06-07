#include<iostream>
using namespace std;
int main()
{
    long long n;
    int i=1,a;
    cin>>n;
    if(n==0) cout<<n;
    else
    {
        if(n<0)
        {
            cout<<'-';
            n*=-1;
        }
        do
        {
            a=n%10;
            if(a==0&&i==1);
            else
            {
                cout<<a;
                i=0;
            }
            n/=10;
        }
        while(n!=0);
    }
    return 0;
}
