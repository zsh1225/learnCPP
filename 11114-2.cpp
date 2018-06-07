#include<fstream>
#include<iostream>


using namespace std;
int main()
{
    ifstream fin("in.txt");
    int a[5],b[5],c=0,d=0;
    for(int q=0; q<5; q++) fin>>a[q];
    for(int q=0; q<5; q++) fin>>b[q];
    for(int i=0; i<10; i++)
    {
        if(a[d]<=b[c])
        {
            cout<<a[d]<<' ';
            if(d==4) break;
            else d++;
        }
        else
        {
            cout<<b[c]<<' ';
            if(c==4) break;
            else c++;
        }
/*        if(d==4) {while(c!=4)
            {
                c++;
                cout>>b[c];
            }}
        else {while(d!=4)
            {
                d++;
                cout>>a[d];
            }}
*/
    }
    fin.close();
    return 0;
}
