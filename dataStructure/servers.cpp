#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1<<20 + 10;
    int dp[lim],graph[23][23],bit[23],deg[23];

    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            deg[a]++;
            deg[b]++;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        int len ;
        for(int mask = 0;mask < (1<<n); ++mask)
        {
            len = 0;
            dp[mask] = INF;
            for(int i=0;i<n;++i)
            {
                if( mask&(1<<i))
                    bit[++len] = i;
            }

        }
        return 0;
    }
