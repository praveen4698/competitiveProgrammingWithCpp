#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    long long int dp[lim][4];
    // 0 first mini,1 first maxi, 2 last mini , 3 last maxi;
    long long int mini[lim][3],maxi[lim][3];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            vector<int> A;
            for(int i=1;i<n+1;++i )
            {
                A.clear();
                int a;
                scanf("%d",&a);
                for(int j=0;j<a;++j)
                {
                    int tt;
                    scanf("%d",&tt);
                    A.push_back(tt);
                }
                int s1=0,s2=INT_MAX,s3=0;
                for(int j=0;j<a;++j)
                {
                    if( A[j] < s2)
                    {
                        s2 = A[j];
                        if( j == 0)
                            s1 = A[a-1];
                        else
                            s1 = A[j-1];
                        if( j == a-1)
                            s3 = A[0];
                        else
                            s3 = A[j+1];
                    }
                }
                mini[i][0] = 1LL*s1;
                mini[i][1] = 1LL*s2;
                mini[i][2] = 1LL*s3;
                s1=0,s2=0,s3=0;
                for(int j=0;j<a;++j)
                {
                    if( A[j] > s2)
                    {
                        s2 = A[j];
                        if( j == 0)
                            s1 = A[a-1];
                        else
                            s1 = A[j-1];
                        if( j == a-1)
                            s3 = A[0];
                        else
                            s3 = A[j+1];
                    }
                }
                maxi[i][0] = 1LL*s1;
                maxi[i][1] = 1LL*s2;
                maxi[i][2] = 1LL*s3;
            }
            for(int i=0;i<n+1;++i)
            {
                for(int j=0;j<4;++j)
                    dp[i][j] = 0;
            }
            for(int i=n-1;i>0;--i)
            {
                int data = mini[i][0];
                long long int t1 = abs(data - mini[i+1][1])*1LL*i + dp[i+1][0];
                long long int t2 = abs(data - maxi[i+1][1])*1LL*i + dp[i+1][1];
                long long int t3 = abs(data - mini[i+1][2])*1LL*i + dp[i+1][2];
                long long int t4 = abs(data - maxi[i+1][2])*1LL*i + dp[i+1][3];
                dp[i][0] = max(max(t1,t2),max(t3,t4));
                data = maxi[i][0];
                t1 = abs(data - mini[i+1][1])*1LL*i + dp[i+1][0];
                t2 = abs(data - maxi[i+1][1])*1LL*i + dp[i+1][1];
                t3 = abs(data - mini[i+1][2])*1LL*i + dp[i+1][2];
                t4 = abs(data - maxi[i+1][2])*1LL*i + dp[i+1][3];
                dp[i][1] = max(max(t1,t2),max(t3,t4));
                data = mini[i][1];
                t1 = abs(data - mini[i+1][1])*1LL*i + dp[i+1][0];
                t2 = abs(data - maxi[i+1][1])*1LL*i + dp[i+1][1];
                t3 = abs(data - mini[i+1][2])*1LL*i + dp[i+1][2];
                t4 = abs(data - maxi[i+1][2])*1LL*i + dp[i+1][3];
                dp[i][2] = max(max(t1,t2),max(t3,t4));
                data = maxi[i][1];
                t1 = abs(data - mini[i+1][1])*1LL*i + dp[i+1][0];
                t2 = abs(data - maxi[i+1][1])*1LL*i + dp[i+1][1];
                t3 = abs(data - mini[i+1][2])*1LL*i + dp[i+1][2];
                t4 = abs(data - maxi[i+1][2])*1LL*i + dp[i+1][3];
                dp[i][3] = max(max(t1,t2),max(t3,t4));

            }
            long long int ans = max(max(dp[1][0],dp[1][1]),max(dp[1][2],dp[1][3]));
            printf("%lld\n",ans);
        }
        return 0;
    }
