#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    for(int i=1;i<=100;i++)
    {
        for(int j=i+1;j<=100;j++)
        {
            for(int k=j+1;k<=j*j*2;k++)
            {
                if(i*i+j*j==k*k) cout<<setw(4)<<i<<setw(4)<<j<<setw(4)<<k<<endl;
            }
        }
    }
    return 0;
}
