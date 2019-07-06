#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = (1<<16);
    long long int dp[lim];
    int n,d;
    long long int solve(vector<int> &A)
    {
        int value = 0;
        int sum = 0;
        int xor1 = 0;
        for(auto a:A)
        {
            value = value*d + a;
            sum+=a;
            xor1^=a;
        }
        if( value == 0)
        {
            dp[value] = 0;
            return 0LL;
        }
        if(dp[value] != -1)
            return dp[value];
        long long int  cost = (xor1)*1LL*(sum);
        long long int mini = INFL;

        for(int i=0;i<n;++i)
        {
            if( A[i] > 0)
            {
                A[i]--;
                mini = min(mini,solve(A));
                A[i]++;
            }
        }
        dp[value] = mini + cost;
        return dp[value];
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d %d",&n,&d);
            vector<int> A;
            for(int i=0;i<n;++i)
                A.push_back(d-1);
            memset(dp,-1,sizeof(dp));
            printf("%lld\n",solve(A));
        }

        return 0;
    }
