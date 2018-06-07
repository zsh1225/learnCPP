#include<iostream>
#include<algorithm>
using namespace std;
int sh(int x,int y);
bool isrp(int a, int b);
int main()
{
	int x,y;
	cin>>x>>y;
	long long q=x*y;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			q+=sh(i,j);
			cout<<"         sh(i,j)"<<sh(i,j)<<endl;
		}
	}
	cout<<q;
	return 0;
}
int sh(int x,int y)
{
	cout<<"x="<<x<<' '<<"y="<<y<<endl;
	int q=0,a,b;
	for(int i;i<100000;i++)
	{
		cout<<"isrp(x,y)"<<isrp(x,y)<<endl;
		if(isrp(x,y)==1) {cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;break;
		}
		
		else  {
			for(int j=2;j<min(x,y);j++){
				if(x%j==0&&y%j==0){
					a=j;
					break;
				}
			}  
			
			if(x%2!=0&&y%2!=0) {cout<<"??????????????????????????"<<endl;break;}
		
		else 
		{
			q++;
			x/=2;
			y/=2;
		}}
	}
	cout<<"q="<<q<<endl;
	return 2*q;
}

bool isrp(int a, int b){
	if(a==1||b==1) return 1;
	if(a <=0 || b<=0 || a==b){  
		return false;
	}else if(a==1 || b==1){  
		return true;
	}else{
		while(1){
			int t = a%b;
			if(t == 0){
				break;
			}else{
				a = b;
				b = t;
			}
		}
		if( b > 1){  
			return false;
		}else{       
			return true;
		}
	}
}
