#include<iostream>
using namespace std;
int w(int);
int main()
{
    int L,R,q=0;
    cin>>L>>R;
    for(int i=L;i<=R;i++) q+=w(i);
    cout<<q;
}

int w(int a)
{
    int i=0,p;
    while(a!=0)
    {
        p=a%10;
        a/=10;
        if(p==2)
            i++;
    }
    return i;
}
