/*
A09-��Ⱥ
ʱ������(��ͨ/Java):1000MS/3000MS          �����ڴ�����:65536KByte
���ύ:23            ����ͨ��:11

����

����һ��������0~9��ɵľ��Σ���������0��������1~9������ӣ�������0����α�Χ�����������ʾһȺ��������һ���������������ж���Ⱥ���ӡ�

����

��һ����������������ʾ���ε�����m������n��1,��m ,n��100��
����Ϊһ��m��n�����־��Ρ�

���

һ��һ��������ʾ��Ⱥ����Ŀ��

��������

4 10
0234500067
1034560500
2045600671
0000000089

�������

4

[�ύ] [���۰�]

|���� |   | ת��ҳͷ|
E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>
using namespace std;
char s[200][200];
void hq(int a,int b)
{ 
	if(s[a][b]=='0') return ;
	s[a][b]='0';
	hq(a,b+1);
	hq(a+1,b);
	hq(a,b-1);
	hq(a-1,b);
	return ;
} 
int main()
{
	
	int a,b,num=0;
	cin>>a>>b;
	for(int i=0;i<=a+1;i++)
	{
		for(int j=0;j<=b+1;j++)
		{
			s[i][j]='0';
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(s[i][j]!='0')
			{
				num++;
				hq(i,j);
			}
		}
	}
	cout<<num;
	return 0;
}
