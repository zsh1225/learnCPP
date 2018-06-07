/*
A09-基因重组
时间限制(普通/Java):1000MS/3000MS          运行内存限制:65536KByte
总提交:20            测试通过:7

描述

众所周知,一个基因可被视为是一种序列,包括了4种核苷酸，可由四个字母表示,A,C、G、T。
一个工程师在进行遗传基因项目的研究，他有这样一项工作：
例如有一个基因“ATCC”。工程师想重新整理它变成“CTCA”。
他能使用两种操作：
（1）交换基因的前两个字母；
（2）移动基因的第一个字母到最后。
例如“ATCC”利用操作2可以变成“TCCA”，利用操作1可以变成“CTCA”。你的任务是写一个程序找出将第一种基因变换成第二种情况的最少操作次数。


输入


第一行为正整数N表示基因的长度（1≤N≤12）。
第二行为原基因序列
第三行为目标基因序列。
对于每一种字母，这两个基因具有相同的数目。



输出

输出一行，表示最少操作步骤。

样例输入

4
ATCC
CTCA

样例输出

2



[提交] [讨论版] 


|返回 |   | 转到页头| 

E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
# include <cstdio>  
# include <cstring>  
# include <iostream>  
using namespace std;  
int n,vis[800000],cnt[20],queue[800000],sum;  
char c[20],s[20];  
  
int id(char i)  
{  
    switch(i)  
    {  
    case 'A': return 0;  
    case 'T': return 1;  
    case 'C': return 2;  
    case 'G': return 3;  
    }  
}  
  
int exchange(int a[])  
{  
    int sum=0,mul=1;  
    for(int i=n-1;i>=0;i--)  
    {  
        sum+=a[i]*mul;  
        mul*=4;  
    }  
    return sum;  
}  
  
void decode(int re,int a[])  
{  
    for(int i = n-1;i>=0;i--)  
    {  
        a[i] = re % 4;  
        re/=4;  
    }  
}  
  
int hash (int a[])  
{  
    int t=sum,rank=0;  
    int c[10];  
    memcpy(c,cnt,sizeof(c));    
    for(int i=0;i<n;i++)         
    {  
        for(int j=0;j<a[i];j++)  
            if(c[j])    rank += t*c[j]/(n-i);      
              
    t = t*c[a[i]]/(n-i);  
    --c[a[i]];  
    }  
    return rank;  
}  
  
int main()  
{  
    //freopen("a.txt","r",stdin);  
    while(cin>>n&&n)  
    {  
        memset(vis,0,sizeof(vis));  
        memset(cnt,0,sizeof(cnt));  
        int current[20],target[20],i,j;  
        sum=1;  
        scanf("%s%s",c,s);  
        for(i=0;i<n;i++)  
        {  
            current[i]=id(c[i]);      
            target[i]=id(s[i]);  
            sum*=i+1;                  
            cnt[current[i]]++;        
        }   
        int currentcode=exchange(current),targetcode=exchange(target);    
          
        for(i=0;i<4;i++)     
            for(j=1;j<=cnt[i];j++)  
                sum/=j;  
    if(currentcode==targetcode)   
    { printf("0\n"); continue; }  
              
    int tail=0,head=0,step=1,ans=-1;  
              
            queue[tail++] = currentcode;  
            vis[hash(current)] = 1;  
              
            for(;head < tail && ans==-1;step++)     
            {  
                int size =tail - head;  
                for(; size ;head++,size--)     
                {  
                    for(i=0;i<2;i++)  
                    {  
                        decode(queue[head],current);     
                    
                        if(i==0)    swap(current[0],current[1]);  
                        else  
                        {  
                            j=current[0];  
                            for(int k=1;k<n;k++)  
                                current[k-1]=current[k];  
                            current[n-1]=j;  
                        }  
                          
                        j=hash(current);      
                          
                        if(!vis[j])  
                        {  
                            vis[j]=1;  
                     currentcode=exchange(current);  
                            if(currentcode==targetcode)  
                            {  
                                ans=step;  
                                break;  
                            }  
                            queue[tail++]=currentcode;  
                        }  
                    } 
                     }  
            }  
            printf("%d\n",ans);  
    }  
    getchar();  
    return 0;  
} 
