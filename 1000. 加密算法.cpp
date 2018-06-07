//神龙数码公司设计了一个加密算法：用a代替z,用b代替y，用c代替x,......，用z代替a。现要求输入一个小写字母，对其进行加密输出。
#include<iostream>
using namespace std;
int main()
{
	char a;
	cin>>a;
	switch(a){
		case 'a': cout<<'z';break;
		case 'b': cout<<'y';break;
		case 'c': cout<<'x';break;
		case 'd': cout<<'w';break;
		case 'e': cout<<'v';break;
		case 'f': cout<<'u';break;
		case 'g': cout<<'t';break;
		case 'h': cout<<'s';break;
		case 'i': cout<<'r';break;
		case 'j': cout<<'q';break;
		case 'k': cout<<'p';break;
		case 'l': cout<<'o';break;
		case 'm': cout<<'n';break;
		case 'n': cout<<'m';break;
		case 'o': cout<<'l';break;
		case 'p': cout<<'k';break;
		case 'q': cout<<'j';break;
		case 'r': cout<<'i';break;
		case 's': cout<<'h';break;
		case 't': cout<<'g';break;
		case 'u': cout<<'f';break;
		case 'v': cout<<'e';break;
		case 'w': cout<<'d';break;
		case 'x': cout<<'c';break;
		case 'y': cout<<'b';break;
		case 'z': cout<<'a';break;
	}
	return 0;
} 
