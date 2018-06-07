#include<iostream>
#include<string>
//#include<cstring>
using namespace std;

void read_num(int a[]);
void print_num(int a[]);
void add_num(int a[],int b[],int c[]);
void sub_num(int a[],int b[],int c[]);
void multiply_num(int a[],int b[],int c[]);
void div_num(int a[],int b[],int c[],int d[]);



int main()
{
    int s1[1000]={0},s2[1000]={0},s3[1000]={0};
//    memset(s1,0,sizeof(s1));
//    memset(s2,0,sizeof(s2));
//    memset(sum,0,sizeof(sum));
    read_num(s1);
    read_num(s2);
    multiply_num(s1,s2,s3);
    cout<<s1[0]<<endl;
    cout<<s2[0]<<endl;
    cout<<s3[0]<<endl;
    print_num(s3);
}


void read_num(int a[])
{
    string s;
    cin>>s;
    a[0]=s.length();
    for(int i=1; i<=a[0]; i++)
        a[i]=s[a[0]-i]-'0';
}

void print_num(int a[])
{
    for(int i=a[0]; i>=1; i--)               //倒叙打印
        cout<<a[i];
}

void add_num(int a[],int b[],int c[])
{
    int carry=0;
    int i=1;
    while(i<=a[0]||i<=b[0])
    {
        c[i]=a[i]+b[i]+carry;
        carry=c[i]/10;
        c[i]%=10;
        i++;
    }
    c[i]=carry;
    c[0]=c[i]==0?--i:i;     //如果进位为0（没有进位）则标志i减少1
    //    if(c[i]==0) c[0]=--i;
//    else c[0]=i;
}

void sub_num(int a[],int b[],int c[])
{
    int i=1;
    while(i<=a[0]||i<=b[0])
    {
        c[i]=a[i]-b[i];
        if(c[i]<0)
        {
            c[i]+=10;
            a[i++]--;
        }
        i++;
    }
    if(c[i-1]==0&&i>1)
        c[0]=i-2;
    else
        c[0]=i-1;
}

void multiply_num(int a[],int b[],int c[])
{
    c[0]=a[0]+b[0];
    for(int i=1;i<=a[0];i++)
        for(int j=1;j<=b[0];j++)
        c[i+j-1]+=a[i]*b[j];
    for(int i=1;i<c[0];i++)
        if(c[i]>9) c[i+1]+=c[i]/10,c[i]%=10;
    while(c[c[0]-1]) c[0]--;
}

void div_num(int a[],int b[],int c[],int d[])
{

}



