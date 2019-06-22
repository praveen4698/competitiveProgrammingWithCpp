#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    vector<pair<int,int> > G[lim];
    int mod;
    long long int ans = 0;
    vector<int> DFS(int ver,int costi = -1,int par=-1)
    {
        vector<int> dp;
        for(int i=0;i<mod;++i)
            dp.push_back(0);
        for(auto it:G[ver])
        {
            int child = it.first;
            int cost = it.second;
            if( child == par)
                continue;
            vector<int> temp = DFS(child,cost,ver);
            ans+=(1LL*temp[0]);
            ans+=(temp[0]*1LL*dp[0]);
            for(int i=1;i<mod;++i)
            {
                ans+=(temp[0]*1LL*dp[i]);
                if( mod%i == 0 && i > 1)
                    ans+=(temp[mod/i]*1LL*dp[i]);
            }

            for(int i=0;i<mod;++i)
                dp[i]+=temp[i];
        }

        vector<int> ret;
        for(int i=0;i<mod;++i)
            ret.push_back(0);
        if( costi != -1)
        {
            for(int i=0;i<mod;++i)
                ret[(i*costi)%mod] = dp[i];
            ret[costi]++;
        }

        return ret;

    }
    int main()
    {
        int n;
        scanf("%d %d",&n,&mod);
        ans = 0LL;
        for(int i=0;i<n-1;++i)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            c = c%mod;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
        vector<int> t = DFS(1);
        printf("%lld\n",ans);
        return 0;
    }
