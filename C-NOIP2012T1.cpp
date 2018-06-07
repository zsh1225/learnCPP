#include<iostream>
#include<string>

using namespace std;

void jm(string k,string c,string m);

int main()
{
    string k,c,m;
    cin>>k;
    cin>>c;
    jm(k,c,m);
    cout<<m;
}

void jm(string k,string c,string m)
{
    int z;
    for(int i=0;i<c.size();i++)
    {
        z=k.size()%c.size();
        if(k(z)>='a')
            m[i]=c[i]-(k[z]-'a');
        else m[i]=c[i]-(k[z]-'A');
        if((c[i]>='a'&&m[i]<'a')||(c[i]<'a'&&m[i]<'A')) m[i]+=26;
    }
}
