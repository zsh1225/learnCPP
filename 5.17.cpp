#include<iostream>
#include<iomanip>


using namespace std;

int main()
{
    int a[11][11]{0};
    int n,x,y,tot=0;
    cin>>n;
    tot=a[x=0][y=0]=1;        //起点为a[0][0]
    while(tot<n*n)
    {
        while(x==0&&!a[x+1][y-1]) a[x][++y]=++tot;     //向右
        while(x!=&&a[x+1][y-1]==1)a[x][++y]=++tot;
        while(y==0&&!a[x-1][y+1]) a[++x][y]=++tot;     //向下
        while(x==0&&!a[x+1][y-1]) a[x][++y]=++tot;
    }

    for(x=0;x<n;++x)
    {
        for(y=0;y<n;++y) cout<<setw(5)<<a[x][y];
        cout<<endl;
    }
    return 0;
}
