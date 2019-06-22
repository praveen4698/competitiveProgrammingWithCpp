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
struct comp
{
    bool operator() (const pair<int,ll>& lhs, const pair<int,ll> & rhs) const
    {
        return lhs.second>rhs.second;
    }
};
const int lim = 1001;
ll dist[lim][lim],far[lim],cost[lim],dp[lim];
vector<pair<int,ll> > G[lim];
void dijkstra(int s)
{
    dist[s][s] = 0ll;
    priority_queue<pair<int,ll>  , vector<pair<int,ll> > , comp > Q;
    Q.push({s,0ll});
    while(!Q.empty())
    {
        pair<int,ll> t = Q.top();
        Q.pop();
        int x = t.first;
        for(auto g:G[x])
        {
            int child = g.first;
            ll cost = g.second;
            if( dist[s][child] > dist[s][x]+cost)
            {
               dist[s][child] = dist[s][x]+cost;
               Q.push({child,dist[s][child]});
            }
        }
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].pb({b,1ll*c});
        G[b].pb({a,1ll*c});
    }
    memset(dist,INFL,sizeof(dist));
    memset(dp,INFL,sizeof(dp));
    dp[x] = 0ll;
    for(int i=1;i<=n;++i)
    {
        cin>>far[i]>>cost[i];
    }
    for(int i=1;i<=n;++i)
        dijkstra(i);

    priority_queue<pair<int,ll>, vector<pair<int,ll> > , comp > Q;
    Q.push({x,0ll});
    while(!Q.empty())
    {
        pair<int,ll> t = Q.top();
        int start = t.first;

        Q.pop();
        for(int i=1;i<=n;++i)
        {
            if(dist[start][i] <= far[start] && (dp[i] > dp[start]+cost[start]))
            {
                dp[i] = dp[start]+cost[start];
                Q.push({i,dp[i]});
            }
        }

    }
    if(dp[y] == INFL)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<dp[y]<<endl;
    return 0;
}


