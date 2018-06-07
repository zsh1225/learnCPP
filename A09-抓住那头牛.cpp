/*
A09-ץס��ͷţ
ʱ������(��ͨ/Java):10000MS/30000MS          �����ڴ�����:65536KByte
���ύ:29            ����ͨ��:14

����

ũ��֪��һͷţ��λ�ã���Ҫץס����ũ���ţ��λ�������ϣ�ũ����ʼλ�ڵ�N(0<=N<=100000)��ţλ�ڵ�K(0<=K<=100000)��ũ���������ƶ���ʽ��
1����X�ƶ���X-1��X+1��ÿ���ƶ�����һ����
2����X�ƶ���2*X��ÿ���ƶ�����һ����
����ţû����ʶ��ũ����ж���վ��ԭ�ز�����ũ������Ҫ������ʱ�����ץסţ�� 

����

����������N��K��

���

һ��������ũ��ץ��ţ��Ҫ���ѵ���С��������

��������

5 17

�������

4



[�ύ] [���۰�] 


|���� |   | ת��ҳͷ| 

E-mail Administrator: Bluesea (Contact)
Copyright ? 2010-2012 www.ntnoi.cn
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N;
int K;

int visit[100001];

struct Step
{
    int x;
    int xx;
    Step(int a,int b):x(a),xx(b){}
};

int main()
{
    cin>>N;
    cin>>K;

    memset(visit,0,sizeof(visit));

    queue<Step> p;
    p.push(Step(N,0));
    visit[N]=1;

    while(!p.empty())
    {
        Step s=p.front();
        if(s.x==K)
        {
            cout<<s.xx<<endl;
            return 0;
        }
        else
        {
            if(s.x-1>0&&visit[s.x-1]!=1)
            {
                p.push(Step(s.x-1,s.xx+1));
                visit[s.x-1]=1;
            }
            if(s.x+1<100001&&visit[s.x+1]!=1)
            {
                p.push(Step(s.x+1,s.xx+1));
                visit[s.xx+1]=1;
            }
            if(s.x*2<100001&&visit[s.x*2]!=1)
            {
                p.push(Step(s.x*2,s.xx+1));
                visit[s.x*2]=1;
            }
        }
        p.pop();
    }
    return 0;

} 



