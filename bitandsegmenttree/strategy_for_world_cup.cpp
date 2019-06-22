#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int mod = 1e9+7;
    int dp[1801][301][10];
    inline int add(int a,int b)
    {
        int ret = a+b;
        return ret%mod;
    }
    int main()
    {
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        for(int j=1;j<301;++j)
        {
            for(int i=0;i<1801;++i)
            {

                for(int k=0;k<10;++k)
                {
                    dp[i][j][k] = add(dp[i][j-1][k],dp[i][j][k]);
                    if( i >= 6 )
                        dp[i][j][k] = add(dp[i][j][k],dp[i-6][j-1][k]);
                    if( i >= 4)
                        dp[i][j][k] = add(dp[i][j][k],dp[i-4][j-1][k]);
                    if(k > 0)
                        dp[i][j][k] = add(dp[i][j][k],dp[i][j-1][k-1]);
                }
            }
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int runs,balls,wicket;
            cin>>runs>>balls>>wicket;
            int ans = 0;
            if( balls*6 < runs)
                printf("0\n");
            else
            {
                for(int i=0;i<=wicket;++i)
                {
                    ans = add(ans,dp[runs][balls][i]);
                  //  printf("%d\n",dp[runs][balls][i]);
                }

                printf("%d\n",ans);
            }

        }
        return 0;
    }
