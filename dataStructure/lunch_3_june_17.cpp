#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    int club[lim],level[lim];
    vector<int> G[lim],G2[lim];
    set<int> S;
    long long int dp[lim];
    map<pair<int,int> ,vector<int> > M;
    void DFS(int ver,int p = -1)
    {
      /*  for(auto it:S)
        {
        //    printf("%d ",it);
            if(club[ver] == club[it] && (level[ver] + 1) == level[it])
                G2[it].push_back(ver);
        } */
        int n = M[make_pair(club[ver],level[ver]+1)].size();
        for( auto it = 0; it < n;++it )
        {
            G2[M[make_pair(club[ver],level[ver]+1)][it]].push_back(ver);
        }
     //   printf("\n");
        M[make_pair(club[ver],level[ver])].push_back(ver);
        for(auto it:G[ver])
            if(it != p)
                DFS(it,ver);

        M[make_pair(club[ver],level[ver])].pop_back();
    }
    void DFS2(int ver)
    {

        if( dp[ver] != -1)
            return ;
        if( level[ver] == 0)
        {
            dp[ver] = 1LL;
            return ;

        }
        dp[ver] = 0LL;
        for(auto it:G2[ver])
        {
            DFS2(it);
            dp[ver]+=dp[it];
            dp[ver] = dp[ver]%mod;

        }
    }

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,x;
            scanf("%d %d",&n,&x);
            for(int i=0;i<=n+1;++i)
            {
                dp[i] = -1LL;
                G[i].clear();
                G2[i].clear();
            }
            for(int i=1;i<n;++i)
            {
                int a;
                scanf("%d",&a);
                G[a].push_back(i);
            }
            for(int i=0;i<n;++i)
                scanf("%d",&club[i]);
            for(int i=0;i<n;++i)
                scanf("%d",&level[i]);


        DFS(0);
    /*    for(int i=0;i<n;++i)
        {
            printf("i =---- %d \n",i);
            for(auto it:G2[i])
                printf("%d",it);
            printf("\n");
        } */
        for(int i=0;i<n;++i)
            if(dp[i] == -1)
                DFS2(i);
        for(int i=0;i<n;++i)
            printf("%d\n",dp[i]);

        }
        return 0;
    }
