#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5 + 10;
    const int logn = 20;
    int dp[lim][logn],level[lim],sub[lim],par[lim];
    int n,m;
    set<int> G[lim];
    struct comp
    {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
            {return lhs.second > rhs.second;}
    };
    // LCA part
    void DFS0(int u)
    {
        for(auto it:G[u])
        {
            if(dp[u][0] != it)
            {
                dp[it][0] = u;
                level[it] = level[u] + 1;
                DFS0(it);
            }
        }
    }
    void preprocess()
    {
        dp[0][0] = 0;
        level[0] = 0;
        DFS0(0);
        for(int j=1;j<logn;++j)
        {
            for(int i=0;i<n;++i)
            {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
    int lca(int a,int b)
    {
        if(level[b] < level[a])
            swap(a,b);
        int d = level[b] - level[a];
        for(int i=0;i<logn;++i)
        {
            if(d&(1<<i))
                b = dp[b][i];
        }
        if( a== b) return b;

        for(int i=logn-1;i>=0;i--)
        {
            if(dp[a][i] != dp[b][i])
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        return dp[a][0];
    }
    //centroid decomposition part
    int nn;
    void DFS1(int u,int p)
    {
        sub[u] = 1;
        nn++;
        for(auto it: G[u])
        {
            if(it != p)
            {
                DFS1(it,u);
                sub[u]+=sub[it];
            }
        }
    }
    int DFS2(int u,int p)
    {
        for(auto it:G[u])
        {
            if(it != p && sub[it] > nn/2)
                return DFS2(it,u);
        }
        return u;
    }
    void decompose(int root,int p)
    {
        nn = 0;
        DFS1(root,root);
        int centroid = DFS2(root,root);
        if( p == -1)
            p = centroid;
        par[centroid] = p;
        for(auto it:G[centroid])
        {
            G[it].erase(centroid);
            decompose(it,centroid);
        }
        G[centroid].clear();
    }
    // query part
    priority_queue<pair<int,int> , vector<pair<int,int > > ,comp > Q[lim];
    int white[lim] ; // 0 means black ,else white;
    int dist(int u,int v)
    {
        return level[u] + level[v] - 2*level[lca(u,v)];
    }
    void update(int x)
    {
        int root = x;
        white[root] = 1 - white[root];
        if(white[root] == 1)
        {
            while(1)
            {
                Q[root].push(make_pair(x,dist(x,root)));
                if( root == par[root])
                    break;
                root = par[root];
            }
        }
    }
    int dist_white(int root)
    {
        priority_queue<pair<int,int> ,vector<pair<int,int> > , comp > &q = Q[root];
        while(!q.empty())
        {
            pair<int,int> t = q.top();
            if(white[t.first] == 0)
                q.pop();
            else
                return t.second;
        }
        return INF;

    }
    long long int query(int x)
    {
            int root = x;
            long long int  ans = INF;
            while(1)
            {
                ans = min(ans,1LL*(dist(x,root)+dist_white(root)));
                if(root == par[root])
                    break;
                root = par[root];
            }
            if(ans >= INF)
                return -1;
            else
                return ans;
    }
    int main()
    {
        cin>>n;
        for(int i = 0;i<n-1;++i)
        {
            int a,b;
            cin>>a>>b;
            G[a-1].insert(b-1);
            G[b-1].insert(a-1);
        }
        preprocess();
        decompose(0,-1);
        for(int i = 0;i<n;++i)
            white[i] =0;
        cin>>m;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            if( a == 0)
                update(b-1);
            else
                printf("%lld\n",query(b-1));
        }
        return 0;
    }

