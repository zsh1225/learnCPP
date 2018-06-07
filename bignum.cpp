#include<iostream>
#include<string>

void add(int str1[],int str2[],int result[]);



using namespace std;

int  main()
{
    int a[10]={1,2,3,4};
    int b[10]={1,2,7,8};
    int re[10]={0};


    add(a,b,re);
    for(int i=4;i>-1;i--) cout<<re[i];
    return 0;
}

void add(int str1[],int str2[],int result[])
{
    int carry=0;
    for(int i=0;i<5;++i)
    {
        result[i]=str1[i]+str2[i]+carry;
        if (result[i]>9)
        {
            carry=result[i]/10;      //取进位数
            result[i]%=10;
        }
    }
}


