//��������Ϣ����Ҫѡһ���鳤����Ϣ��һ����n���ˣ��ֱ���1��n��ţ�����m���˲�����ͶƱ����Ʊ�����루Ʊ������m div 2�����˽���ѡΪ�鳤��
//�������ݽ���֪��m���˷ֱ�ƱͶ����˭����ͳ�Ƴ�˭��������������Ϣ����鳤��
#include<iostream>
using namespace std;
int main()
{
	long long n,a,w=-1,q[10000];
	int m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a;
		q[a]++;
		if(q[a]>m/2){
			w=a;break;
		} 
	}
	cout<<w;
}
