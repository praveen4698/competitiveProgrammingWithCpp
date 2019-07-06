#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e6+10;
    int A[lim];
    long long int sum[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,h;
            scanf("%d %d",&n,&h);
            for(int i=0;i<n+1;++i)
                A[i] = 0,sum[i] = 0;
            for(int i=0;i<n;++i)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                A[a]--;
                A[b+1]++;
            }
            int prev = 0;
            for(int i=0;i<n;++i)
            {
                prev+=A[i];
                sum[i] = 1LL*n + 1LL*prev ;
            }
            for(int i=1;i<n;++i)
                sum[i]+=sum[i-1];
            long long int ans = sum[h-1];
            for(int i=h;i<n;++i)
            {
                ans = min(ans,sum[i]-sum[i-h]);
            }
            printf("%lld\n",ans);
        }
        return 0;
    }

