//����ҳ���λ����abcd������������ϵ������
//    a=b,c=d��abcdΪ��ȫƽ����(��ĳ��������ƽ��)
#include<iostream>
using namespace std;
int main()
{
	int m,a,b,c,d;
	for(int i=32;i<=99;i++){
		m=i*i;
		a=m/1000;
		b=m/100-a*10;
		d=m%10;
		c=(m%100-d)/10;
		if(a==b&&c==d) cout<<m<<endl;
	}
	return 0;
} 
