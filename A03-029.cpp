/*����һ���ַ����ԡ�.���������������ֺͷ������ַ����硰A123X456Y7A.������302ATB567BC.����
��ӡ�ַ���������������ָ�����������ַ�������������ɵ�������ÿ������ռһ�У���ͳ�ƹ��ж��ٸ�������*/
#include<iostream>
using namespace std;
int main()
{
	char a;
	int b=0;
	while(a!='.'){
		cin>>a;
		if(a-'0'>=0&&a-'0'<=9){
			b++;
			while(a-'0'>=0&&a-'0'<=9){
				cout<<a;
				cin>>a;
			}
			cout<<endl;
		}
    }
    cout<<b; 
	return 0;
}

