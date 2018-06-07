#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	int b=0;
		getline(cin,a);
		for(int i=0;i<a.size();i++){
	    b+=a[i]-'0';
        }
	cout<<b;
	return 0;
}

