#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
const int logn = 20;
int dp[lim][logn],level[lim],par[lim],ans[lim],sub[lim];
set<int> g[lim];
int n,m;
// LCA part upto lca
void DFS0(int u)
{

    for(auto it:g[u] )
    {
        if( dp[u][0] != it )
        {
            dp[it][0] = u;
            level[it] = level[u] + 1;
            DFS0(it);

        }
    }
}
void preprocess()
{
    level[0] = 0;
    dp[0][0] = 0;
    DFS0(0);
    for(int j =1;j < 20;++j)
        for(int i = 0;i < n;++i)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<logn;i++)
		if(d&(1<<i))
			b=dp[b][i];
	if(a==b)return a;
	for(int i=logn-1;i>=0;i--)
		if(dp[a][i]!=dp[b][i])
			a=dp[a][i],b=dp[b][i];
	return dp[a][0];
}

//centroid decomposition part
int nn;
void DFS1(int u,int p)
{
    sub[u] = 1;
    nn++;
    set<int>::iterator it;
    for(it = g[u].begin(); it != g[u].end(); ++it)
    {
        if( *it != p)
        {
            DFS1(*it,u);
            sub[u]+=sub[*it];
        }
    }
}
int DFS2(int u,int p )
{
    set<int>::iterator it;
    for(it = g[u].begin(); it != g[u].end() ; ++it)
    {
        if( *it != p && sub[*it]> nn/2)
            return DFS2(*it,u);
    }
    return u;
}
void decompose(int root,int p)
{
    nn = 0;
    DFS1(root,root);
    int centroid = DFS2(root,root);
    if( p == -1)p = centroid;
    par[centroid] = p;
    set<int>::iterator it;
    for(it = g[centroid].begin();it != g[centroid].end();++it)
    {
        g[*it].erase(centroid);
        decompose(*it,centroid);
    }
    g[centroid].clear();
}
// question part;
int dist(int u,int v)
{
	return level[u] + level[v] - 2*level[lca(u,v)];
}
void update(int u)
{
    int x = u;
    while(1)
    {
        ans[x] = min(ans[x],dist(x,u));
        if( par[x] == x)
            break;
        x = par[x];
    }
}
int query(int u)
{
    int x = u;
    int res = INF;
    while(1)
    {
        res = min(res,dist(u,x)+ans[x]);
        if( x == par[x])
            break;
        x = par[x];
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        g[a-1].insert(b-1);
        g[b-1].insert(a-1);
    }
    preprocess();
    decompose(0,-1);
    for(int i = 0;i<n;++i)
        white[i] =0;

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if( a == 1)
            update(b-1);
        else
            printf("%d\n",query(b-1));
    }
    return 0;
}
