#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,a,b,x[26][26]= {0};
    cin>>n;
    a=n/2+1;
    b=1;
    for(int i=1; i<=n*n; i++)
    {
        x[a][b]=i;
        a++;
        b--;
        if(a>n&&b<1){a--;b+=2;}
        else if(a>n)a=1;
        else if(b<1)b=n;
        if(x[a][b]!=0){a--;b+=2;}
    }
    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=n; i++)
            cout<<setw(4)<<x[i][j];
        cout<<endl;
    }

    return 0;
}
