//市三中信息组需要选一个组长。信息组一共有n个人，分别用1到n编号，其中m个人参与了投票。得票数过半（票数大于m div 2）的人将被选为组长。
//输入数据将告知这m个人分别将票投给了谁，请统计出谁将担任市三中信息组的组长。
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
