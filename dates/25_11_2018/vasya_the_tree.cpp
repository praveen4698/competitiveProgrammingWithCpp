#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9+7;
const ll mod = 998244353;

const int lim = 300005;
ll bit[lim+1];
void update(int x, ll val)
{
      for(; x <= lim; x += x&-x)
          bit[x] += val;
      
}
ll query(int x)
{
     ll sum = 0ll;
     for(; x > 0; x -= x&-x)
        sum += bit[x];
     return sum;
}
// first = depth and second = value 
vector<pair<int,ll> > q[lim];
ll ans[lim];
vector<int> G[lim];
void DFS(int ver,int par,int level){

    for(auto a:q[ver]){
        int depth = a.first;
        ll value = a.second;
        update(level,value);
        update(level+depth+1,-value);
    }
    ans[ver] = query(level) ;
    for(int i:G[ver]){
        if( i == par){
            continue;
        }
        DFS(i,ver,level+1);
    }
    for(auto a:q[ver]){
        int depth = a.first;
        ll value = a.second;
        update(level,-value);
        update(level+depth+1,value);
    }

}
int main()
{
    memset(bit,0ll,sizeof(bit));
    memset(ans,0ll,sizeof(ans));
    int n,m;
    scan(n);
    for(int i=0;i<n-1;++i){
        int a,b;
        scan2(a,b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    scan(m);
    while(m--){
        int ver,depth;
        ll value;
        scanf("%d %d %lld",&ver,&depth,&value);
        q[ver].push_back(make_pair(depth,value));
    }
    DFS(1,-1,1);
    for(int i=1;i<=n;++i){
        printf("%lld ",ans[i]);
    }
    return 0;
}
