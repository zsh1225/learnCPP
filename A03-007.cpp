//求两个整数的最大公约数。 
#include<iostream>
using namespace std;
int f(int,int);
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<'('<<m<<','<<n<<")="; 
    if(n>m)
    {
        int a;
        a=m;
        m=n;
        n=a;
    }
    cout<<f(m,n);
    return 0;
}

int f(int t1,int t2)
{
    int t3;
    t3=t1%t2;
    if(t3==0) return t2;
    else return f(t2,t3);
}
