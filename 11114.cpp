#include <iostream>
using namespace std;
int main()
{
    int a[5],b[5],c[10];
    int sa=0,sb=0,sc=0;
    for(int i=0; i<5; i++) cin>>a[i];
    for(int i=0; i<5; i++) cin>>b[i];
    while(sa<5&&sb<5)
        if (a[sa]<b[sb])c[sc++]=a[sa++];
        else c[sc++]=b[sb++];
    while(sa<5)
        c[sc++]=a[sa++];
    while(sb<5)
        c[sc++]=b[sb++];
    for(int i=0; i<10; i++) cout<<c[i]<<" ";
}
