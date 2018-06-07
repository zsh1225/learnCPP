/*模式识别的“中心”问题：
       模式识别的一个关键问题是判别图形的“中心”，当图形经过扫描仪扫描后，得到一个实数矩阵，我们首先要找到该图形的“中心”，
	   然后才能开始识别。
	   设实数矩阵由m行n列组成(1≤100，n≤100)，所谓的中心(i,j)是使第i行上边元素(不包括第i行)的总和与第i行下边元素(不包括第i行)
	   的总和之差的绝对值最小，
	   而且第j列左边元素(不包括第j列)的总和与第j列右边元素(不包括第j列)的总和之差的绝对值最小。
      现已知一扫描所得的实数矩阵，求其“中心”。若有多个“中心”，给出任意一个“中心”即可。*/
//第一行输入两个整数m、n，以下m行是实数矩阵，每行各有n个实教。在每一行中，数据之间只有一个空格。每行的行首、行末无多余空格。
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int m,n,x=0,y=0;
	float a[101][101]={0},r,up=0,down=0,min=99999;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
	    }
	}
	for(int i=1;i<=m;i++){
		for(int s=1;s<i;s++){
		    for(int w=1;w<=n;w++){
			    up+=a[s][w];
	        }
	    }
	    for(int s=i+1;s<=m;s++){
		    for(int w=1;w<=n;w++){
			    down+=a[s][w];
	        }
	    }
	    r=fabs(up-down);
	    cout<<"r1="<<r<<endl;
	    if(r<min){
			min=r;
			x=i;
	    }
	}
	min=99999;
	for(int i=1;i<=n;i++){
		for(int s=1;s<=m;s++){
		    for(int w=1;w<i;w++){
			    up+=a[s][w];
	        }
	    }
	    for(int s=1;s<=m;s++){
		    for(int w=i+1;w<=n;w++){
			    down+=a[s][w];
	        }
	    }
	    r=fabs(up-down);
	    cout<<"r2="<<r<<endl;
	    if(r<min){
			min=r;
			y=i;
	    }
	}
	cout<<"Center=("<<x<<','<<y<<')';
	return 0;
}
