//求两个整数的最小公倍数。
#include<iostream>
using namespace std;
int main()
{
	int m,n,i;
    cin>>m>>n;
    cout<<'['<<m<<','<<n<<"]=";
    if(n>m)
    {
        int a;
        a=m;
        m=n;
        n=a;
    }
    for(i=m;i<=m*n;i+=m) if(i%n==0) break;
    cout<<i;
} 
