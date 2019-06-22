#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

pair<ll,int> solve(int at,int mask,vector<int> &A,vector<int> &M,vector<map<int,pair<ll,int> > > &dp)
{
    if( at == -1)
        return {0,0};
    if(dp[at].find(mask) != dp[at].end())
        return dp[at][mask];
    pair<ll,int> notake = solve(at-1,mask,A,M,dp);
    if( mask&M[at])
    {
        return dp[at][mask] = notake;
    }
    pair<ll,int> take = solve(at-1,mask|M[at],A,M,dp);
    take.first+=A[at];
    take.second++;
    pair<ll,int> good = notake;
    if( take.first > good.first)
        good = take;
    else if( take.first == good.first)
        good.second = max(good.second,take.second);
    return dp[at][mask] = good;

}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> A(n),M(n);
        for(int i=0;i<n;++i)
        {
            cin>>A[i];
            int x= A[i],xd=0;
            while(x)
            {
                xd|=1<<(x%10);
                x/=10;
            }
            M[i] = xd;
        }
        vector<map<int,pair<ll,int > > > dp(n);
        pair<ll,int> ans = solve(n-1,0,A,M,dp);
        cout<<ans.second<<endl;
    }
    return 0;
}
