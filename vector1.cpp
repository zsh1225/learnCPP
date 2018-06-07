#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    vector<int>::iterator l;
    int a;
    for(int i=1; i<10; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    for(l=v.end();l!=v.begin();l--)
        cout<<*l<<endl;
}
