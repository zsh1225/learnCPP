/*����

�ж�һ�������Ƿ�Ϊ�����������������뷴��������ͬ����

����

��������a(������9λ)

���

���ǻ������������YES�������������NO��

��������

1234321

�������

YES*/ 

#include<iostream>
#include<string>
using namespace std;
int main()
{
	bool w=1;
	string q;
	cin>>q;
	for(int i=q.size()-1,j=0;j<=i;i--,j++){
		if(q[j]!=q[i]) w=0;
	}
	if(w==0) cout<<"NO";
	else cout<<"YES";
	return 0;
} 
