/*
A09-������
ʱ������(��ͨ/Java):1000MS/3000MS          �����ڴ�����:65536KByte
���ύ:11            ����ͨ��:7

����

   ����lzz��������������n�������μӡ���n����½½����������lzz�ĳ������ֳ���һ�Ŵ��Σ�ÿ����һ������lzz�ͻ������ӳ��ε���߻��ұ߽�ȥ���¡�����������̫�࣬lzz�Ѿ�æ���ˣ������ڵ�hxy����֮�������������ڳ��������ŵ��˴�������������˭����ʱ����Ҳ�޷������ش���������������һ�������������ش�������⡣

����

   ��һ����һ������n��1<=n<=20000��
   ����n����һ������a���ַ���Name����a=0��ʾ������Ǵ���߽��볤�εģ���a=1ʱ��ʾ������Ǵ��ұ߽��볤�εġ�Name��ʾ��i���������˵����֡�

���

   ��n�У����α�ʾ�����ϴ����ҵ��˵����֡�
   ע����Ŀ�е�hxy������Ϊ��n���˵��е�һ������������n���˵���֮������ġ�

��������

10
0 LZZ
0 HSY
0 TSW
1 LHS
1 WKA
0 LWJ
1 HT
0 ZZB
1 DYL
0 ZJX

�������

ZJX
ZZB
LWJ
TSW
HSY
LZZ
LHS
WKA
HT
DYL

[�ύ] [���۰�]

|���� |   | ת��ҳͷ|
E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string l[20010],r[20010];
	int n,x=1,y=1,h;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h;
		if(h==0)
        {
            cin>>l[x];
            x++;
        }

		else if(h==1)
        {
            cin>>r[y];
            y++;
        }

	}
	for(int i=x-1;i>=1;i--)
	cout<<l[i]<<endl;
	for(int i=1;i<y;i++)
	cout<<r[i]<<endl;
	cout<<r[y]; 
	return 0;
}
