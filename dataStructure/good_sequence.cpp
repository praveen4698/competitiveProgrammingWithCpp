#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    int main()
    {
        int dp[lim] ;
        int A[lim];
        bool prime[lim];
       // memset(dp,1,sizeof(dp));
       // memset(A,0,sizeof(A));
        for(int i=0;i<lim;++i)
        {
            dp[i] = 1;
            prime[i] = true;
            A[i] = 0;
        }
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            int a;
            scanf("%d",&a);
            A[a] = 1;
        }
        for(int i=2;i<lim;++i)
        {
            //int prev = dp[i];
            if( prime[i] == true)
            {
                int prev = 0;
                if( A[i] == 1)
                    prev = 1;
                for(int j=2*i;j<lim;j = j+i)
                {
                    prime[j] = false;
                    if( A[j] == 1)
                    {
                        dp[j] = max(dp[j],prev +1);
                        prev = max(dp[j],prev+1);
                    }
                }
            }
          // printf("%d = %d\n",i,dp[i]);
        }
        int ans = -1;
        for(int i=2;i<lim;++i)
            ans = max(dp[i],ans);
        cout<<ans;
        return 0;
    }
