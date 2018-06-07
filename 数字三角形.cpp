#include<iostream>
#include<algorithm>
#define MAX 101
int maxsum(int i,int j);
using namespace std;

int d[MAX][MAX];
int n;


int maxsum(int i,int j)
{
    if(i==n) return d[i][j];
    return max(maxsum(i+1,j),maxsum(i+1,j+1))+d[i][j];
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        cin>>d[i][j];
    cout<<maxsum(1,1)<<endl;
    return 0;
}

