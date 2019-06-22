#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 501;
int dp[lim][lim] ;
int solve(int i,int j)
{
    if( i == 1 && j == 1)
            return dp[i][j] = 0;
    if( dp[i][j] != -1)
        return dp[i][j];
    int t1=INF,t2=INF,t3=INF;
    if( __gcd(i,j) != 1)
    {
        int x = __gcd(i,j);
        t1 = solve(i/x,j/x);
    }
    if( i != 1)
        t2 = solve(i-1,j);
    if( j != 1)
        t3 = solve(i,j-1);
    return dp[i][j] = 1+min(t1,min(t2,t3));
}
int main()
{
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<501;++i)
        for(int j=1;j<501;++j)
            dp[i][j] = solve(i,j);
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]<<endl;
    }
    return 0;
}
