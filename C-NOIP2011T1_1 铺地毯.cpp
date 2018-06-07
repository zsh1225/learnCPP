#include<iostream>
using namespace std;
int main()
{
    int n,a[10000],b[10000],g[10000],k[10000],x,y,q=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    }
    cin>>x>>y;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x&&x<=a[i]+g[i]&&b[i]<=y&&y<=b[i]+k[i]) q=i;
    }
    cout<<q;
    return 0;
}
