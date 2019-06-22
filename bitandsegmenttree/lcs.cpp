#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e3+10;
int dp[1001][1001];
int main()
{
    int t;
    scanf("%d",&t);
    int x = 1;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n,m;
        scanf("%d %d",&n,&m);
        string A,B;
        cin>>A;
        cin>>B;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if( A[i] == B[j])
                    dp[i+1][j+1] = max(dp[i+1][j+1],1+dp[i][j]);
                else
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }

        }
        printf("Case %d: %d\n",x,n+m-dp[n][m]);
        x++;
    }
    return 0;
}
