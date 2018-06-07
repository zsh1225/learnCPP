#include <iostream>
using namespace std;
int main()
{
    int a[52]{1},s=0;
    for(int i=1; i<52; i++)
    {
        for(int j=0;j<52; j+=i)
        {
            a[j]=!a[j];
        }
    }
    for(int i=0; i<52; i++) if(a[i])
        {
            cout<<i<<endl;
            s++;
        }
    cout<<"total="<<s;
    return 0;
}
