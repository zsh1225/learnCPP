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
        if(b&1!=0) ans*=base;   //ֻҪb���Ϊ1���Ͱ�base����ȥ,Ϊ0������
        base*=base;             //ѭ��һ�ξͽ�base^2^0->base^2^1->base^2^2->base^2^3
        b>>=1;                  //��b�Ķ���������һλ
    }
    return ans;
}





