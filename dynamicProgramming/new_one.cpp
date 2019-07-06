#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[1001];
    int dp1[1001][10001],dp2[1001][10001];
    int main()
    {
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&A[i]);
        }
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=x;++j)
             {
                 dp1[i][j] = 0;
                 dp2[i][j] = 0;
             }
        }
        dp1[0][0] =1;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=x;++j)
            {
                if(dp1[i-1][j] == 1)
                {
                    if( A[i]+j > x )
                    {
                        if( i+1 <= n && A[i]+j-A[i+1] < x)
                        {
                           // printf("%d %d\n",i,j);
                            dp2[i+1][A[i]+j-A[i+1]] = max(dp2[i+1][A[i]+j-A[i+1]],1+dp2[i-1][j]);
                            dp1[i+1][A[i]+j-A[i+1]] = 1;
                        }
                    }
                    else
                    {
                        dp2[i][j+A[i]] = max(dp2[i][j+A[i]],dp2[i-1][j]);
                        dp1[i][j+A[i]] = 1;
                    }
                    if( j-A[i] >= 0)
                    {
                        dp2[i][j-A[i]] = max(dp2[i][j-A[i]],dp2[i-1][j]);
                        dp1[i][j-A[i]] = 1;
                    }
                }
               // dp2[i][j] = max(dp2[i][j] ,dp2[i-1][j]);
            }
        }
        int ans = 0;
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=x;++j)
                ans = max(ans,dp2[i][j]);
        }
        printf("%d\n",ans);
        return 0;

    }
