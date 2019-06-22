#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 10001;
int A[lim],T[lim],dp[1001][lim][2];
int main()
{
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;++i)
        cin>>A[i];
    for(int i=0;i<n;++i)
        cin>>T[i];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i)
    {


    for(int x=0;x<=t;++x)
    {

            if( x-T[i] >= 0)
            {
                dp[i+1][x][0] = max(dp[i][x][0],A[i]+dp[i][x-T[i]][0]);
                dp[i+1][x][1] = max(dp[i][x][1],max(2*A[i]+dp[i][x-T[i]][0],A[i]+dp[i][x-T[i]][1]));
            }
          //  printf("i = %d ,dp[%d][0] %d dp[%d][1] = %d\n",i,x,dp[x][0],x,dp[x][1]);


    }
    }
    int ans = 0;
    for(int i=0;i<=t;++i)
        ans = max(ans,dp[n][i][1]);
    cout<<ans<<endl;
    return 0;
}
