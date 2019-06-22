#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    int v;
    bool BFS(int rg[v][v],int s,int t,int parent[])
    {
        bool visited[v];
        memset(visited,false,sizeof(visited));
        queue<int> Q;
        Q.push(s);
        parent[s] = -1;
        visited[s] = true;
        while(!Q.empty())
        {
            int f = Q.front();
            Q.pop();
            for(int i=0;i<V;++i)
            {
                if( visited[i] == false && rg[f][i] > 0)
                {
                    Q.push(i);
                    parent[i] = f;
                    visited[i] = true;
                }
            }
        }
        return (visited[t] == true);
    }
    int ford_fulkerson(int G[v][v],int s,int t)
    {
        int rg[v][v];
        for(int i=0;i<v;++i)
            for(int j=0;j<v;++j)
                rg[i][j] = G[i][j];
        int parent[v];
        int max_flow = 0;
        while(BFS(rg,s,t,parent))
        {
            int path_flow = INT_MAX;
            for(int v=t;v!=s;v=parent[v])
            {
                int u = parent[v];
                path_flow = min(path_flow,rg[u][v]);
            }
            for(int v=t;v!=s;v=parent[v])
            {
                int u = parent[v];
                rg[u][v]-=path_flow;
                rg[v][u]+=path_flow;
            }
            max_flow+=path_flow;

        }
        return max_flow;
    }
    int main()
    {

        return 0;
    }
