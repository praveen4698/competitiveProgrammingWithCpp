#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
vector<pair<int,int> > G[150];
int dp[101][128][128],ans;
void DFS(int ver,int prev,int xr)
{
    if( dp[ver][prev][xr] )
        return ;
    ans = max(ans,xr);
    dp[ver][prev][xr] = 1;
    for(auto g:G[ver])
        DFS(g.fi,g.se,xr^(g.se&prev));
}

int main()
{
    int n,m;
    scan2(n,m);
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        scan3(a,b,c);
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    ans = 0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
        DFS(i,0,0);
    cout<<ans<<endl;
    return 0;
}


