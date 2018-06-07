#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	int b=0;
	while(a[a.size()-1]!='$')
	{
		getline(cin,a);
		for(int i=0;i<a.size();i++){
	    if(a[i]==' ') b++;
        }		
	}
	cout<<"Space="<<b;
	return 0;
}

