#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> a;
    for(int i=0;i<10;i++) a.push_back(i);
    reverse(a.begin(),a.end());
    cout<<a[1]<<endl;
    return 0;
}
