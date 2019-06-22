#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
const ll mod = 1e9+7;
vi G[lim];
int sub[lim];
bool visited[lim];
int DFS(int ver,int par=-1)
{
    if( visited[ver] == true)
    {
        return 0;
    }
    visited[ver] = true;

    int temp = 0;
    for(auto a:G[ver])
    {
        if(a == par)
            continue;
        temp+=DFS(a,ver);
    }
    return (temp+1);
}

int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n,m;
        S2(n,m);
        memset(sub,0,sizeof sub);
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;++i)
            G[i].clear();
        for(int i=0;i<m;++i)
        {
            int a,b;
            S2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        ll ways = 1ll;
        ll ans = 0;
        for(int i=1;i<=n;++i)
        {
            if( visited[i] == false)
            {
                ans++;
                int tt = DFS(i);
                ways  = ways*1ll*tt;
                ways%=mod;
            }
        }
        printf("%lld %lld\n",ans,ways);
    }
    return 0;
}


