/*

1015. ���ڼ� (Standard IO)
ʱ������: 1000 ms  �ռ�����: 262144 KB  �������� 
��Ŀ����
��������1~7�ı�ʾ����һ�������գ������Ӧ�����ڼ���Ӣ�����ơ�
�����1�����Monday;
�����2�����Tuesday;
�����3�����Wednesday;
�����4�����Thursday;
�����5�����Friday;
�����6�����Saturday;
�����7�����Sunday;
����
����һ������
���
�����Ӧ��Ӣ������
��������

1

�������

Monday

���ݷ�Χ����

��Դ/����: CCF��ѧ������������������ƪ��ϰ3.4.2

��Ȩ���� ? �й������ѧ��
�й������ѧ��ӵ�б���Ŀ�������桢���ݣ��İ�Ȩ

���й���Ա��ӵ���Ŀ ʹ�ô˰�Ȩ/��Ȩ��ʽ

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	switch(a){
		case 1:cout<<"Monday";break;
		case 2:cout<<"Tuesday";break;
		case 3:cout<<"Wednesday";break;
		case 4:cout<<"Thursday";break;
		case 5:cout<<"Friday";break;
		case 6:cout<<"Saturday";break;
		case 7:cout<<"Sunday";break;
	}
	return 0;
}
