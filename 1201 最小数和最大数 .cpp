#include<iostream>
using namespace std;
int main()
{
    int n,z,max,min;
    cin>>n>>z;
    max=min=z;
    for(int i=0;i<n-1;i++)
    {
        cin>>z;
        if(z>max)max=z;
        if(z<min)min=z;
    }
    cout<<min<<' '<<max;
    return 0;
}
