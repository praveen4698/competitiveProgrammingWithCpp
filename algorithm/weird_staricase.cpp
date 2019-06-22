#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 501;
    int dp[lim],x[lim];
    int visit[lim],n ;
    int solve(int i)
    {
        if(visit[i] > 101)
            return INF;
        if(i<0 || i>n-1)
            return INF;

        if(i == n-1)
            return 0;
        visit[i]++;
        if(visit[i]  < 5)
            printf("%d = %d\n",i,dp[i]);
        solve(i+1);
        solve(i+x[i]);
        dp[i] = 1 + min(dp[i+1],dp[i+x[i]]);

        }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&n);
            for(int i=0;i<n;++i )
                scanf("%d",&x[i]);
            for(int i=0;i<n;++i)
            {
                dp[i] = INF;
                visit[i] = 0;
            }
            dp[0] = solve(0);
            printf("%d\n",dp[0]);
        }
        return 0;
    }
