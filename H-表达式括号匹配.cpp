#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    int w=0;
    string a;
    stack<char> p;
    cin>>a;
    p.push('#');
    for(int i=0;i<a.size();i++)
    {
        switch(a[i])
        {
            case '(': p.push('(');break;
            case ')': if(p.top()=='(') p.pop();else if(p.top()=='#') w=1;  break;
        }
    }
    p.pop();
    if(p.empty()&&w==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
