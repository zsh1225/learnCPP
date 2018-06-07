#include<iostream>
#include<math.h>
using namespace std;
int main()
{
   int n,m,k,x;
   cin>>n>>m>>k>>x;
   k=pow(10,k);
   k%=n;
   cout<<k<<endl;
   for(int i=0;i<=k;i++)
   {
       x+=m;
       if(x>=n)x-=n;
       cout<<x<<endl;
   }
   cout<<x;
   return 0;
}
