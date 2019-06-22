#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    int A[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,d;
            scanf("%d %d",&n,&d);
            long long int sum = 0;
            for(int i=0;i<n;++i)
            {
                scanf("%d",&A[i]);
                sum+=(1LL*A[i]);
            }
            if( sum%n != 0)
            {
                printf("-1\n");
                continue;
            }
            long long int mean = sum/(1LL*n);
            long long int ans = 0;
            int flag = 0;
            for(int i=0;i<n;++i)
            {
                if( A[i] == mean)
                    continue;
                if( A[i] > mean )
                {
                    if( i+d >= n)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        long long int xx = 1LL*A[i] - mean;
                        ans+=xx;
                        A[i+d]+=xx;
                    }

                }
                else if( A[i] < mean)
                {
                    if( i+d >= n)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        long long int xx = mean - 1LL*A[i];
                        ans+=xx;
                        A[i+d]-=xx;

                    }


                }
            }
            if( flag == 1)
                printf("-1\n");
            else
                printf("%lld\n",ans);

        }
        return 0;
    }
