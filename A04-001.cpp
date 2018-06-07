//输入今天是星期几的序号(星期天的序号为0，星期一为1，以此类推)，输出明天是星期几的英文单词。
#include<iostream>
using namespace std;
int main()
{
	int m;
	cin>>m;
	switch(m){
		case 0:cout<<"Tomorrow is Monday.";break;
		case 1:cout<<"Tomorrow is Tuesday.";break;
		case 2:cout<<"Tomorrow is Wednesday.";break;
		case 3:cout<<"Tomorrow is Thursday.";break;
		case 4:cout<<"Tomorrow is Friday.";break;
		case 5:cout<<"Tomorrow is Saturday.";break;
		case 6:cout<<"Tomorrow is Sunday.";break;
	}
	return 0;
} 
