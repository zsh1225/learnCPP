//������������ڼ������(����������Ϊ0������һΪ1���Դ�����)��������������ڼ���Ӣ�ĵ��ʡ�
#include<iostream>
using namespace std;
int main()
{
	int m;
	cin>>m;
	switch(m){
		case 0:cout<<"Tomorrow is Monday.";break;
		case 1:cout<<"Tomorrow is Tuesday.";break;
		case 2:cout<<"Tomorrow is Wednesday.";break;
		case 3:cout<<"Tomorrow is Thursday.";break;
		case 4:cout<<"Tomorrow is Friday.";break;
		case 5:cout<<"Tomorrow is Saturday.";break;
		case 6:cout<<"Tomorrow is Sunday.";break;
	}
	return 0;
} 
