#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    int w=0;
    stack<char> p;
    string a;
    cin>>a;
    p.push('#');
    for(int i=0;i<a.size();i++)
    {
        switch(a[i])
        {
            case '(': p.push('(');break;
            case ')': if(p.top()=='(') p.pop();else if(p.top()=='#') w=1;               break;
            case '[': p.push('[');break;
            case ']': if(p.top()=='[') p.pop();break;
        }
    }
    p.pop();
    if(p.empty()&&w==0) cout<<"OK";
    else cout<<"Wrong";
}
