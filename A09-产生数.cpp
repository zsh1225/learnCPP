/*
A09-������
ʱ������(��ͨ/Java):1000MS/3000MS          �����ڴ�����:65536KByte
���ύ:26            ����ͨ��:23

����

����һ������n��n<=2000����k���任����k��15��������
�� 1�����ֿ��Ա任����1�����֣�
�� �����У��ұߵ����ֲ���Ϊ�㡣
���磺n=234��k=2����Ϊ
2 �� 5
3 �� 6
���������234�����任����ܲ�����������Ϊ������ԭ����234��534��264��564��4�ֲ�ͬ�Ĳ�������
�󾭹�����εı任��0�λ��Σ����ܲ��������ٸ���ͬ����������Ҫ�������ͬ���������� 

����

n
k
x1 y1
x2 y2
�� ��
xn yn

���

��ʽΪһ������������������������������

��������

234
2
2 5
3 6

�������

4

��ʾ


 




[�ύ] [���۰�] 


|���� |   | ת��ҳͷ| 

E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include<iostream>
#include<queue>
using namespace std;
const int maxn=10001;
const int maxm=16;
int n,k,head,x,y,mod,tmp;
int exist[maxn],que[maxn],a[maxm],b[maxm];
int main()
{
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a[i]>>b[i];
	}
	exist[n]=1;que[1]=n;head=1;
	for(int tail=0;head>=tail;)
	{
		x=que[++tail];
		y=x;
		mod=1;
		while(x>0)
		{
			tmp=x%10;
			x/=10;
			for(int i=0;i<k;i++)
			{
				if(a[i]==tmp)
				{
					int p=y+(b[i]-tmp)*mod;
					if(exist[p]==0){
						exist[p]=1;que[++head]=p;
					}
				}
				
			}
			mod*=10;
		}
	} 
	cout<<head<<endl;
	return 0;
}
