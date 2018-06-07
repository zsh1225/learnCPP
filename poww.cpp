#include <iostream>

using namespace std;

long long poww(int a,int b);

int main()
{
    cout<<poww(21,30);
}

long long poww(int a,int b)
{
    long long ans=1,base=a;
    while(b!=0)
    {
        if(b&1!=0) ans*=base;   //只要b最后为1，就把base乘上去,为0则跳过
        base*=base;             //循环一次就将base^2^0->base^2^1->base^2^2->base^2^3
        b>>=1;                  //将b的二进制右移一位
    }
    return ans;
}





