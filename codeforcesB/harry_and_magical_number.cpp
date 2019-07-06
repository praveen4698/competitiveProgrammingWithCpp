#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5;
    long long int A[lim],sum[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long long int n,S;
            scanf("%lld %lld",&n,&S);
            for(int i=0;i<n;++i)
                scanf("%d",&A[i+1]);
            sort(A+1,A+n+1);
            sum[0]=0;
            for(int i=1;i<n+1;++i)
                sum[i] = sum[i-1] + A[i];
            long long int ans = INFL;
            A[0] = 0;
            if( S == sum[n])
            {
                printf("%lld\n",A[n]+1);
                continue;
            }
            for(int i=1;i<n+1;i++)
            {
               // printf("%d\n",n-i+1);
                if( (S-sum[i-1])%((long long int)n-i+1) == 0)
                {
                    long long int x = (S-sum[i-1])/((long long int)n-i+1);
                    if( x < A[i] && x >= A[i-1])
                        ans = min(ans,x);
                }
            }
            if(ans == INFL)
                printf("-1\n");
            else
                printf("%lld\n",ans);
        }
        return 0;
    }
