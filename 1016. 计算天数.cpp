/*

1016. �������� (Standard IO)
ʱ������: 1000 ms  �ռ�����: 262144 KB  �������� 
��Ŀ����
����������·ݣ�����¹��ж����졣
����
���������ո������������year��month���ֱ��ʾ��ݺ��·�
���
�����Ӧyear��һ��month����µ�������
��������

2000 2

�������

29

���ݷ�Χ����
1000<=year<=3000,1<=month<=12

��Դ/����: CCF��ѧ������������������ƪ��ϰ3.4.3

��Ȩ���� ? �й������ѧ��
�й������ѧ��ӵ�б���Ŀ�������桢���ݣ��İ�Ȩ

���й���Ա��ӵ���Ŀ ʹ�ô˰�Ȩ/��Ȩ��ʽ

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a%400==0) a=1;
	else if(a%100==0) a=0;
	else if(a%4==0) a=1;
	else a=0;
	switch(b)
	{
		case 1:cout<<31;break;
		case 2:cout<<28+a;break;
		case 3:cout<<31;break;
		case 4:cout<<30;break;
		case 5:cout<<31;break;
		case 6:cout<<30;break;
		case 7:cout<<31;break;
		case 8:cout<<31;break;
		case 9:cout<<30;break;
		case 10:cout<<31;break;
		case 11:cout<<30;break;
		case 12:cout<<31;break;
		
	}
	return 0;
}
