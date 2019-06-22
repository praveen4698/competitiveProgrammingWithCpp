#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    long long int sum[lim],A[lim];
    long long int sum2[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;++i)
                scanf("%lld",&A[i]);
            sort(A,A+n);
            sum[n-1] = A[n-1];
            for(int i=n-2;i>=0;--i)
                sum[i] = A[i] + sum[i+1];
            long long int ans = -INFL;
            sum2[0] = A[0];
            for(int i=1;i<n;++i)
                sum2[i] = A[i]+ sum2[i-1];
            ans = (n)*sum2[n-1];
            for(int i=0;i<n-1;++i)
            {
                ans = max(ans,sum2[i] + 1LL*(n-1-i)*sum[i+1]);
            }
            printf("%lld\n",ans);


        }
        return 0;
    }
