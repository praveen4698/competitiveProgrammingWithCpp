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
const int lim = 1e6;
vector<pair<int,ll> > G[lim];
ll cost[lim];
ll ans ;
ll DFS(int ver,int par=-1){
    
    if( (G[ver].size() == 1 && par != -1) || G[ver].size() == 0){
        ans = max(ans,cost[ver]);
        return cost[ver];
    }
    vector<ll> temp; 
    //  temp.push_back(cost[ver]);
    for(auto &t:G[ver]){
        int child =  t.first;
        ll w = t.second;
        if( child == par)   
            continue;
        ll ret = DFS(child,ver);
        // cout<<child<<" "<<ret<< "  sds"<<endl;
        ret-=w;
        temp.push_back(ret);
    }
    sort(all(temp));
    reverse(all(temp));
    if( temp.size() == 1){
        if( temp[0] > 0){
            ans = max(temp[0]+cost[ver],ans);
            return temp[0]+cost[ver];
        }
        else{
            ans = max(cost[ver],ans);
            return cost[ver];
        }
    }
    else{
        if( temp[0] >= 0 && temp[1] >= 0){
            ans = max(temp[0]+temp[1]+cost[ver],ans);
        }
        else if( temp[0] > 0 && temp[1] < 0){
            ans = max(temp[0]+cost[ver],ans);
        }
        else{
            ans = max( cost[ver],ans);
        }
        if(temp[0] > 0)
            return temp[0] + cost[ver];
        else 
            return cost[ver];
    }
}
int main()
{
    int n;
    scan(n);
    for(int i=1;i<=n;++i)
        cin>>cost[i];
    for(int i=0;i<n-1;++i){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    ans = 0;
    ll t = DFS(1);
    cout<<ans<<endl;

    return 0;
}
