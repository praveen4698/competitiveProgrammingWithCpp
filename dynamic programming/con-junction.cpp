#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 10007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5 + 70;
    vector<int> G[lim];
    int ver[lim][2],ways[lim][2];
    void DFS(int v,int par = -1)
    {
        ver[v][0] = 0;
        ver[v][1] = 1;
        ways[v][0] = 1;
        ways[v][1] = 1;
        for(auto i:G[v])
        {
            if(i == par)
                continue;
            DFS(i,v);
            ver[v][0]+=ver[i][1];
            ways[v][0] = (ways[v][0]*ways[i][1])%mod;

            ver[v][1] += min(ver[i][0],ver[i][1]);
            if(ver[i][0] < ver[i][1])
                ways[v][1] = (ways[v][1]*ways[i][0])%mod;
            else if( ver[i][1] < ver[i][0])
                ways[v][1] = (ways[v][1]*ways[i][1])%mod;
            else
                ways[v][1] = (ways[v][1]*(ways[i][1] + ways[i][0]))%mod;
        }
    }

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<=n;++i)
                G[i].clear();
            for(int i=1;i<n;++i)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                G[a].push_back(b);
                G[b].push_back(a);
            }
            DFS(1);
            if(ver[1][0] < ver[1][1])
                printf("%d %d\n",ver[1][0],ways[1][0]);
            else if(ver[1][1] < ver[1][0])
                printf("%d %d\n",ver[1][1],ways[1][1]);
            else
                printf("%d %d\n",ver[1][0],(ways[1][1]+ways[1][0])%mod);
        }
        return 0;
    }

