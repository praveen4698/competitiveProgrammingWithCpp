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
const int lim = 1e6+10;
int G[lim],cost[lim],visited[lim],parent[lim];
vector<vector<int> > Cycles;
void DFS(int ver){
    visited[ver] = 1;
    int child = G[ver];
    if( visited[child] != 2){
        if( visited[child] == 1){
            vector<int> cycle;
            cycle.push_back(child);
            int x = child;
            while(G[x] != ver){
                x = G[x];
                cycle.push_back(x);
                // cout<<x<<endl;
            }
            cycle.push_back(ver);
            Cycles.push_back(cycle);
        }
        else{
            parent[child] = ver;
            DFS(child);
        }
    }
    visited[ver] = 2;
}
int main()
{
    int n;
    scan(n);
    for(int i=1; i<=n; ++i)
        scan(cost[i]);
    for(int i=1; i<=n; ++i)
        scan(G[i]);
    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));

    for(int i=1; i<=n; ++i){
        if(visited[i] == 0){
            parent[i] = i;
            DFS(i);
        }
    }
    int ans = 0;
    for(auto cycle:Cycles){
        int temp = cost[cycle[0]];
        for(int a:cycle)
            temp = min(temp,cost[a]);
        ans+=temp;
    }
    cout<<ans<<endl;
    return 0;
}
