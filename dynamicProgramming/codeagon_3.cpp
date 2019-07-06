#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 5e5+10;
    int parent[lim];
    map<int,vector<int> > M;
    int par(int x)
    {
        if( parent[x] == x)
            return x;
        return parent[x] = par(parent[x]);
    }
    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n+1;++i)
            parent[i] = i;
        int cycle = 0;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            int fx = par(a);
            int fy = par(b);
            if( fx != fy)
            {
                parent[fx] = fy;
            }
            else
                cycle++;
        }
        for(int i=1;i<n+1;++i)
        {
            M[par(i)].push_back(i);
        }
        long long int ans = 0;
        vector<int> tt;
        for(auto it:M)
        {
            int si = it.second.size();
            ans+=(si*1LL*(si-1));
            if( si > 1)
                tt.push_back(si);
        }
        //printf("%lld\n",ans);
        sort(tt.begin(),tt.end());
        if(cycle >= 2)
        {
            printf("%lld",ans);
            return 0;
        }
        else
        {
            if( cycle <= 1)
            {
                tt[0]--;
                ans-=(2ll*tt[0]);
            }
            if( cycle <= 0)
            {
                if( tt[0] >= 2)
                {
                    tt[0]--;
                    ans-=(2LL*tt[0]);
                }
                else
                {
                    tt[1]--;
                    ans-=(2LL*tt[1]);
                }
            }
            printf("%lld",ans);
        }
        return 0;
    }
