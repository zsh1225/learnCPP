#include <iostream>
using namespace std;
int main()
{
    int a[10];
    for (int i=0; i<10; i++) cin>>a[i];
    int min=a[0],m=0;
    for(int i=1; i<10; i++)
    {
        if(min>a[i])
        {
            min=a[i];
            m=i;
        }
    }
    for(int i=m;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=min;
    for(int i=0;i<10;i++) cout<<a[i]<<" ";
}
