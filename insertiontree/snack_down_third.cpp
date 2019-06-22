#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    long long int  A[lim],first[lim],last[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            long long int sum = 0;
            for(int i=1;i<=n;++i)
            {
                scanf("%lld",&A[i]);
                sum+=A[i];
            }
            long long int prev=1;
            for(int i=1;i<=n;++i)
            {
                first[i] = min(A[i],prev);
                prev = first[i]+1;
            }
            prev= 1;
            for(int i=n;i>0;--i)
            {
                last[i] = min(A[i],prev);
                prev = last[i]+1;
            }

            long long int ans = INFL;
            for(int i=1;i<n;++i)
            {
                long long int len;
                if( first[i] == last[i+1])
                    len = first[i];
                else
                {
                    len = min(first[i],last[i+1]) + 1;
                }
                long long int temp = 1LL*len*len;
                ans = min(ans,sum-temp);
            }
            printf("%lld\n",ans);
        }

        return 0;
    }
