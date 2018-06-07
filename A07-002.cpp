#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int ss(int);
int fun1(int);
int fun2(int);
int main()
{
    int t1,t2;
//    cout<<setw(6)<<1;
    for(int i=1;i<=500;i++)
    {
        if(ss(i)==0)
        {
            t1=fun1(i);
            t2=fun2(i);
            if(t1==t2) cout<<setw(6)<<i;
        }
    }
    return 0;
}



int ss(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0) return 0;
    return 1;
}

int fun1(int a)
{
    int q=0;
    while(a!=0)
    {
        q+=(a%10);
        a/=10;
    }
    return q;
}

int fun2(int a)
{
    int n=0;
    while(a!=1)
    {
        for(int i=2;i<=a;i++)
        {
            if(ss(i)==1&&a%i==0)
            {
                n+=fun1(i);
                a/=i;
                break;
            }
        }
    }
    return n;
}
