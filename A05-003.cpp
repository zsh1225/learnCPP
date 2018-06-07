//求由整数a的各位数字构成的最大整数。 
#include<iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	int a[10000],q=0;
	char w;
	while((w = getchar()) != '\n' ){
		a[q]=w-'0';
		q++;
	}
	sort(a,a+q);
	for(int i=q-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
