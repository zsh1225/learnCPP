# include <bits/stdc++.h>

using namespace std;
#define MAXSTRLEN 25500   		//用户可在25500以内定义最长串长
typedef char SString[MAXSTRLEN+1];//0号单元存放串的长度,所以+1 

void getInput(SString &S, SString &T, int &pos) {//引用参数
    cout << "请输入主串：" << endl;
    cin >> &S[1];//主串存储到S组的第二个元素开始的位置。
    S[0] = strlen(&S[1]);//存长度 
    cout << "请输入子串：" << endl;
    cin >> &T[1];//子串存储到T组的第二个元素开始的位置。
    T[0] = strlen(&T[1]);//存长度
    cout << "请输入匹配起始位置：" << endl;
    cin >> pos;
    for(;pos<=0;)
    {
    	cout<<"请输入正数pos"<<endl;
    	cin>>pos;
	}
	pos = pos%S[0];
    if((T[0]+pos-1)>S[0])
    {
    	cout<<"温馨提示：字串的长度加上比较起始位置已经超过主串的长度，在主串中必然找不到字串的，请检查是否 主/子 颠倒"<<endl; 
	}
}

//BF算法
int Index(SString S, SString T, int pos)
{
	//返回模式T在主串S中第pos个字符之后第s一次出现的位置。若不存在，则返回值为0
	//其中，T非空，1≤pos≤StrLength(S)
	int i = pos;
	int j = 1;
	int ci = 0;
	while(i <= S[0]&&j <= T[0])
	{
		if(S[i]==T[j])
		{
			++i;
			++j;
		} //继续比较后继字符
		else
		{ 
			ci++;
			cout<<"i="<<i<<"j="<<j<<"不相等，指针后退第"<<ci<<"次"<<endl; 
			i=i-j+2;
			j=1;
			cout<<"后退后"<<"i=" <<i<<"  j="<<j<<endl;
		} //指针后退重新开始匹配
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
	//return 0;
}//Index

//计算next函数值
void get_next(SString T, int next[])
{ //求模式串T的next函数值并存入数组next
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T[0])
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
}//get_next

//KMP1算法
int Index_KMP1(SString S, SString T, int pos, int next[])
{ 	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1≤pos≤StrLength(S)
	int i = pos, j = 1,ci=0,sum=0,t=1,pos2=1,flag = 0;
	while (i <= S[0] && j <= T[0]){
		if (j == 0 || S[i] == T[j]) // 继续比较后继字
		{
			++i;
			++j;
			ci++;
			sum++;
		}
		else{
			ci++;
			if(j<=T[0])
			{
				sum ++;
			}
			cout<<"i: "<<pos<<"->"<<i<<"j: "<<pos2<<"->"<<j<<"   "<<"比较"<<ci<<"次"<<" "<<"j=Next["<<j<<"]="<<next[j]<<endl;
			if(next[j]==0){
				flag++;
			}
			pos2 = next[j];
			j = next[j]; // 模式串向右移动
			ci=0;
			t ++;
			pos=i;
		}
			
	}
		if (j > T[0]){// 匹配成功
		cout<<"匹配成功"<<endl; 
		cout<<"匹配总次数："<<sum-flag<<endl;
		cout<<"匹配总趟数"<< t<<endl;
		return i - T[0];
	} 
	else{
		cout<<"匹配失败"<<endl;
		return 0;
	} 
}//Index_KMP2
//KMP2算法
int Index_KMP2(SString S, SString T, int pos, int next[])
{ 	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1≤pos≤StrLength(S)
	int i = pos, j = 1,ci=0,sum=0,t=1,pos2 = 1,flag=0;
	while (i <= S[0] && j <= T[0]){
		if (j == 0 || S[i] == T[j]) // 继续比较后继字
		{
			++i;
			++j;
			ci++;
			sum++;
		}
		else{
			ci++;
			if(j<=T[0])
			{
				sum ++;
			}
			cout<<"i: "<<pos<<"->"<<i<<"j: "<<pos2<<"->"<<j<<"   "<<"比较"<<ci<<"次"<<" "<<"j=Nextval["<<j<<"]="<<next[j]<<endl;
			if(next[j]==0){
				flag++;
			}
			pos2 = next[j];
			j = next[j]; // 模式串向右移动
			ci=0;
			t ++;
			pos=i;
		}
			
	}
		if (j > T[0]){// 匹配成功
		cout<<"匹配成功"<<endl; 
		cout<<"匹配总次数："<<sum-flag<<endl;
		cout<<"匹配总趟数"<< t<<endl;
		return i - T[0];
	} 
	else{
		cout<<"匹配失败"<<endl;
		return 0;
	}
	
		
	
}//Index_KMP2

//算法4.4　计算next函数修正值
void get_nextval(SString T, int nextval[])
{ // 求模式串T的next函数修正值并存入数组nextval
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T[0])
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		} else
			j = nextval[j];
}//get_nextval
void inspect()//密码校验 
{
	int key1=666666;
	int key2 = 0;
	cout<<"请输入登录密码:"<<endl;
	cin>>key2;
	if(key1 ==  key2){
		cout<<"核验完毕，自己人"<<endl; 
	}
	else{
		cout<<"密码错误，请再次输入登录密码（还剩2次机会）："<<endl;
		cin>>key2;
		if(key1 ==  key2){
		cout<<"核验完毕，自己人"<<endl; 
		}
		else{
			cout<<"密码错误，请再次输入登录密码（还剩1次机会）："<<endl;
			cin>>key2;
			if(key1 ==  key2){
				cout<<"核验完毕，自己人"<<endl; 
			}
			else{
					cout<<"警告！警告！入侵！入侵！您没有访问权限，程序会在3秒内结束"<<endl; 
					exit(0);
			} 
		} 
	}
}

void menu()
{
	cout<<"*\t\t\t请选择功能列表\t\t\t\t\t*\n"<<endl;
	cout<<"*********************************************************\n"<<endl;
	cout<<"1.输入主串、子串和匹配起始位置\n"<<endl;
	cout<<"2.朴素的模式匹配算法\n"<<endl;
	cout<<"3.KMP改进算法(Next[ ])\n"<<endl;
	cout<<"4.KMP改进算法(NextVal[ ])\n"<<endl;
	cout<<"0.退出程序\n"<<endl;
	cout<<"*********************************************************\n"<<endl;
	
}

int main(){
	//inspect(); 
	//welcome1();
	int choice;
	SString S;//char S[MAXSTRLEN+1];
	SString T;//char T[MAXSTRLEN+1];
	int pos;
	int *next = new int[T[0]+1]; // 生成T的next数组
	int *nextval = new int[T[0]+1]; // 生成T的nextval数组
	while(1){
		menu();
		cin>>choice;
		switch(choice)
		{
		    case 1:
                getInput(S, T, pos);
                break;
			case 2:
					cout<<"主串和子串在第"<<Index(S,T,pos)<<"个字符处首次匹配\n";
					break;
			case 3:	
					get_next(T, next);
					cout << "Next数组的值为：";
					for (int i = 1; i <= T[0]; i++) {
						cout << next[i] << " ";
					}
					cout << endl;
					cout << "主串和子串在第" << Index_KMP1(S, T, pos, next) << "个字符处首次匹配\n";
					break;
			case 4:	
					get_nextval(T, nextval);
					cout << "Nextval数组的值为：";
					for (int i = 1; i <= T[0]; i++) {
						cout << nextval[i] << " ";
					}
					cout << endl;
					cout << "主串和子串在第" << Index_KMP2(S, T, pos, nextval) << "个字符处首次匹配\n";
					break;
    		case 0:exit(0);
    		default:printf("输入有误\n");
		}
	}
	return 0;
}
