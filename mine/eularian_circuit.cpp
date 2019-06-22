#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, e, deg[N];
vector<pair<int,int> > edgeList;
bool visited[N];
set<int> adj[N];


void check_connectivity(int v){
    
    visited[v] = true;
    for(auto e : adj[v]){
        int vv = v ^ edgeList[e].first ^ edgeList[e].second;
        if(!visited[vv])
            check_connectivity(vv);
        }
}

void euler_dfs(int v){
    
    while(!adj[v].empty()){
        
        int e = (*adj[v].begin());
        int vv = v ^ edgeList[e].second ^ edgeList[e].second;

        if(edgeList[e].first!= v)
            swap(edgeList[e].first, edgeList[e].second);

        adj[v].erase(adj[v].begin());
        adj[vv].erase(e);

        euler_dfs(vv);
        }
}


int main(){
    
    cin>>n>>e;
    for(int i=0;i<e;i++){
        
        int a, b;
        cin>>a>>b;
        adj[a].insert(i);
        adj[b].insert(i);
        deg[a]++;
        deg[b]++;
        edgeList.push_back({a, b});
    }

    check_connectivity(1);
    for(int i=1;i<=n;i++){
        
        if(!visited[i] || deg[i] % 2 == 1){
                cout<<"NO";
                return 0;
        }
    }

    euler_dfs(1);

    cout<<"YES\n";
    for(int i=0;i<e-1;i++)
        cout<<edgeList[i].first<<" "<<edgeList[i].second<<endl;
    cout<<edgeList[e-1].first<<" "<<edgeList[e-1].second;
    return 0;
}
