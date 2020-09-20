#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;
const int limit =  1000000;
vector<int> G[limit];
vector<bool> visited(limit, false);


void DFS(int child, int parent) {

    if( visited[child])
        return;
    visited[child] = true;
    for(int i:G[child]) {
        if( i == parent) 
            continue;
        else{
            DFS(i, child);
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m; ++i) {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int prev = 1;

    DFS(1, -1);

    vector<pair<int,int> > ans;
    for(int i=2;i<=n;++i) {
        if( visited[i] == false) {
            DFS(i, -1);
            ans.push_back({i, 1});
        }

    }

    int ret = int(ans.size());
    cout<<ret<<endl;
    for(int i=0;i<ret; ++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
