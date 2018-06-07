#include<iostream>
using namespace std;
int main()
{
    int m,n,a[1000]={0},f=0,t=0,s=0;
    cin>>m>>n;
    do{
        t++;
        if(t==m+1) t=1;
        if(a[t]==0) s++;
        if(s==n)
        {
            s=0;
            a[t]=1;
            f++;
        }
    }while(f!=m);
    cout<<"The monkey king is no."<<t<<endl;
    return 0;
}
