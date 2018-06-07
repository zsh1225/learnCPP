#include<iostream>
using namespace std;
int main()
{
    int n,z,total=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>z;
        total+=z;
    }
    cout<<total;
    return 0;
}
