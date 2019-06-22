#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
ll cost[lim];
vi G[lim];
ll ans ;
ll DFS(int ver ,int par = -1)
{
    ll temp = 0;
    for(auto child:G[ver])
    {
        if( child == par)
            continue;
        ll x = DFS(child, ver);
        if( x > 0)
            temp+=x;
    }
    temp+=(1LL*cost[ver]);
  //  cout<<ver<<" "<<temp<<" "<<cost[ver]<<endl;
    ans = max(temp,ans);
    return temp;
}

int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n;
        scan(n);
        for(int i=1;i<=n;++i)
        {
            G[i].clear();
            cin>>cost[i];
        }
        for(int i=0;i<n-1;++i)
        {
            int a,b;
            scan2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        ans = -INFL;
        ll tt = DFS(1);
        cout<<ans<<endl;
    }
    return 0;
}


