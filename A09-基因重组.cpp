/*
A09-��������
ʱ������(��ͨ/Java):1000MS/3000MS          �����ڴ�����:65536KByte
���ύ:20            ����ͨ��:7

����

������֪,һ������ɱ���Ϊ��һ������,������4�ֺ����ᣬ�����ĸ���ĸ��ʾ,A,C��G��T��
һ������ʦ�ڽ����Ŵ�������Ŀ���о�����������һ�����
������һ������ATCC��������ʦ��������������ɡ�CTCA����
����ʹ�����ֲ�����
��1�����������ǰ������ĸ��
��2���ƶ�����ĵ�һ����ĸ�����
���硰ATCC�����ò���2���Ա�ɡ�TCCA�������ò���1���Ա�ɡ�CTCA�������������дһ�������ҳ�����һ�ֻ���任�ɵڶ�����������ٲ���������


����


��һ��Ϊ������N��ʾ����ĳ��ȣ�1��N��12����
�ڶ���Ϊԭ��������
������ΪĿ��������С�
����ÿһ����ĸ�����������������ͬ����Ŀ��



���

���һ�У���ʾ���ٲ������衣

��������

4
ATCC
CTCA

�������

2



[�ύ] [���۰�] 


|���� |   | ת��ҳͷ| 

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
