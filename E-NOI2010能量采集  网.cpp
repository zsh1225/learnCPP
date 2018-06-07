#include<cstdio>
#include<cstring>
  
inline int min(int a,int b){return a<b?a:b;} const="" int="" maxn="100010;" long="" cnt[maxn];="" main()="" {="" n,m;="" while(~scanf("%d%d",&n,&m))="" t="min(n,m);" for(int="" i="2;i<=t;i++)//gcd" =="" cnt[i]="(long" long)(n="" i)*(m="" i);="" :="" the="" number="" of="" whose="" gcd="" is="" k*i="">=1;i--)
            for(int k=2;k*i<=t;k++)
                cnt[i]-=cnt[k*i];//to get the real number of whose gc is i
        long long ans = 0;
        for(int i=1;i<=t;i++)
            ans+=2*(i-1)*cnt[i];
        printf("%lld\n",ans+(long long)n*m);
    }
    return 0;
}</b?a:b;}></cstring></cstdio>
