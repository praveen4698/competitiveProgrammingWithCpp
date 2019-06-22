#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

vector<pair<int, long long> >adj[65537];
bool visited[65537];
long long sum[65537];
int x[200001],y[200001];
long long z[200001];

void dfs(int vertex)
{
    if(visited[vertex])
        return;

    visited[vertex]=true;
    for(int i=0;i<adj[vertex].size();i++)
    {
        if(!visited[adj[vertex][i].first])
        {
            //set its cumulative sum value..
            sum[adj[vertex][i].first]=sum[vertex]+adj[vertex][i].second;
            dfs(adj[vertex][i].first);
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    //accepting the intervals..
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%lld",&x[i],&y[i],&z[i]);
        adj[x[i]-1].push_back(mp(y[i],z[i]));
        adj[y[i]].push_back(mp(x[i]-1,-z[i]));
    }

    //now perform dfs on every sum node..
    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    //now validating the found sums...if they're genuine..
    for(int i=0;i<m;i++)
    {
        if((sum[y[i]]-sum[x[i]-1])!=z[i])
        {
            puts("-1");
            return 0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        printf("%lld ",sum[i]-sum[i-1]);
    }
    return 0;
}
