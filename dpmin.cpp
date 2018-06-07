#include <iostream>
#include <algorithm>

using namespace std;

void dpmin(int coin[],int s,int solu[]);

int main()
{
    int n,s;
    cin >> n >> s;
    int coin[n]= {0},solu[s];
    for(int i = 0; i < n; ++i) cin >> coin[i];
    dpmin(coin,s,solu);
    for(int i=0; i<s; ++i)cout<<solu[i]<<endl;
    return 0;
}

void dpmin(int coin[],int s,int solu[])
{

}
