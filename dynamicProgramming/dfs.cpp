#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

     int child ;
    int dp[100001],dp1[1000001];
    char G[100001];
    int n;
    void DFS()
    {
        if(child >= n )
         {
             dp[n] = 0;
             return;
         }

        int p = child;
        if(G[p] == 'l')
        {
            dp[p] = 0;
            dp1[p] = 0;
            return ;
        }
        child++;
        int c1 = child;
        if(dp[c1] == -1)
            DFS();
        dp1[p] = max(dp1[p],1+dp1[c1]);
        dp[p]+=(1 + dp1[c1]);
        child++;
        c1 = child;
        if(dp[c1] == -1)
            DFS();
        dp1[p] = max(dp1[p],1+dp1[c1]);
        dp[p]+=(1 + dp1[c1]);
        return;
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s",G);
            n = strlen(G);
            for(int i=0;i<n;++i)
            {
                dp1[i] = -1;
                dp[i] = -1;
            }
            child = 0;
            DFS();
            int ans = -1;
            for(int i=0;i<n;++i)
                ans = max(ans,dp1[i]);
            printf("%d\n",ans);
        }
    }
