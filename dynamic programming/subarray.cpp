#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    char opp(char c)
    {
        if( c == ')')
            return '(';
        if( c ==  ']')
            return '[';
        if( c == '}')
            return '{';
        if( c == '>')
            return '<';
        return '.';
    }
    const int lim = 1e5+10;
    long long int dp[lim],bal[lim],A[lim],sum[lim];
    char S[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            S[0] = '$';
            scanf("%s",S+1);
            for(int i=0;i<n+1;++i)
                bal[i] = 0;
            sum[0] = 0LL;
            for(int i=1;i<n+1;++i)
            {
                scanf("%lld",&A[i]);
                sum[i] = A[i] + sum[i-1];
            }
            stack<int> st;
            st.push(0);
            for(int i=1;i<n+1;++i)
            {
                if( S[st.top()] == opp(S[i]))
                {
                    bal[i] = st.top();
                    st.pop();
                }
                else
                    st.push(i);
            }
            long long int ans = 0LL;
            for(int i=1;i<n+1;++i)
            {
                dp[i] = 0LL;
             //   printf("%d\n",bal[i]);
                if( bal[i])
                    dp[i] = max(dp[i],sum[i]-sum[bal[i]-1]+dp[bal[i]-1]);

                ans = max(ans,dp[i]);
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
