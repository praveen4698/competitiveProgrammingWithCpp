#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 2e6 ;
    int bit[lim],pos[lim];
    long long int sum[lim];
    bool comp(int a,int b)
    {
        return make_pair(sum[a],a) < make_pair(sum[b],b);
    }
    void modify(int x)
    {
        while(x<lim)
        {
            bit[x]++;
            x+=(x&(-x));
        }
    }
    int query(int x)
    {
        int res=0;
        while(x > 0)
        {
            res+=bit[x];
            x = x&(x-1);
        }
        return res;
    }

    int main()
    {
        int n,k;
        scanf("%d %d",&n,&k);
        sum[0] = 0;
        for(int i=1;i<n+1;++i)
        {
            int a;
            scanf("%d",&a);
            a = a-k;
            sum[i] = sum[i-1] + 1ll*a;
            pos[i] = i;
        }
       //  for(int i = 0;i <= n;++i)
        //    printf("%d %d\n",pos[i],sum[i]);
        sort(pos,pos+n+1,comp);
        long long int ans = 0;
        for(int i=0;i<n+1;++i)
        {
            ans+=(1ll*query(pos[i]+1));
            modify(pos[i]+1);
        }
        printf("%lld\n",ans);
        return 0;
    }
