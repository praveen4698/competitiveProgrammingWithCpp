#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    vector<int> G[lim],degree[lim];
    int sol[lim],parent[lim];
    int par(int x)
    {
        if( parent[x] == x)
            return x;
        return parent[x]=par(parent[x]);
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
       {

        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n+1;++i)
        {
            G[i].clear();
            degree[i].clear();
        }
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i=0;i<n+1;++i)
        {
            parent[i] = i;
            int x = G[i].size();
            degree[x].push_back(i);
        }
        int ans = n;
        for(int i=n-1;i>=0;--i)
        {
            sol[i] = ans-1;
            for(int deg:degree[i])
            {
                for(int k:G[deg])
                {
                    int deg_ch = G[k].size();
                    int def_f = i;
                    if( deg_ch < i)
                        continue;
                    int fx = par(deg);
                    int fy = par(k);
                  //  printf("%d %d\n",fx,fy);
                    if(fx != fy)
                    {
                        ans--;
                        parent[fx] = fy;
                    }
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            if( i == n-1)
                printf("%d\n",sol[i]);
            else
                printf("%d ",sol[i]);
        }
    }
        return 0;
    }
