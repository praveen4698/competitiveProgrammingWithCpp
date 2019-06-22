#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
vector<int> G[1001];
int t[1001],h;
pair<int,int> mask[(1<<10)][25],dp[1001][25];

    void DFS(int v)
    {
        for(int u: G[v]) DFS(u);
        int n = G[v].size();
        for(int msk = 0; msk < (1<<n);++msk)
            for(int p = 0;p<=h;++p)
                mask[msk][p] = make_pair(1001,h);
        for(int p = 0;p+t[v]<=h;++p)
            mask[0][p] = make_pair(0,p+t[v]);
        for(int p = h - t[v]+1;p<=h;++p)
            mask[0][p] = make_pair(1,t[v]);
        for(int msk = 0; msk <(1<<n);++msk)
        {
            for(int i = 0;i<n;++i)
            {
                if( ((msk>>i)&1) == 0)
                {
                    for(int p = 0;p <= h;++p)
                    {
                        pair<int,int> &a = mask[msk][p];
                        pair<int,int> &b = mask[msk|(1<<i)][p];
                        pair<int,int> &c = dp[G[v][i]][a.second];
                        b = min(b,make_pair(a.first+c.first,c.second));
                    }
                }
            }
        }
        for(int p = 0;p<=h;++p)
            dp[v][p] = mask[(1<<n)-1][p];
    }



    int main()
    {
        int z;
        scanf("%d",&z);
        while(z--)
        {
            int n;
            scanf("%d %d",&n,&h);
            for(int i = 0;i<n;++i)
                G[i].clear();
            for(int i = 0; i<n;++i)
                scanf("%d",&t[i]);
            for(int i = 0;i<n;++i)
            {
                int m;
                scanf("%d",&m);
                while(m--)
                {
                    int a;
                    scanf("%d",&a);
                    G[i].push_back(a-1);
                }
            }
            DFS(0);
            printf("%d\n",dp[0][h]);
        }
        return 0;
    }
