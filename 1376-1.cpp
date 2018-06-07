#include<iostream>
using namespace std;
int main()
{
    int n,m,k,x,tmp=1,base=10;
    cin>>n>>m>>k>>x;
    while(k)
    {
        if(k&1) tmp=(tmp*(base%n))%n;
        k=k>>1;
        base=(base*base)%n;
    }
    tmp=(tmp*(m%n))%n;
    tmp=(tmp+x)%n;
    cout<<tmp<<endl;
    return 0;
}
