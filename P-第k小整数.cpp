/*����

����n����������n��10000��Ҫ�����n���������еĵ�k����С��������ͬ��С������ֻ����һ�Σ���k��1000����������С��30000��

����

��һ��Ϊn��k;
�ڶ��п�ʼΪn����������ֵ���������ÿո������

���

��k����С������ֵ�����޽⣬�������NO RESULT����

��������

10 3
1 3 3 7 2 5 1 2 4 6

�������

3

��Ŀ��Դ

ntNOI.cn
*/ 

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,a[10001],b[10001],w=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,(a+1)+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) {
		w++;
		b[w]=a[i];
		}
	}
	if(w<k) cout<<"NO RESULT";
	else cout<<b[w];
	return 0;
}




