#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e3;
    vector<int> G[lim],G1[lim];
    int cost[lim],duration[lim];
    int start[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        int aa = 1;
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n+1;++i)
            {
                G[i].clear();
                G1[i].clear();
            }
            for(int i=0;i<n;++i)
                scanf("%d",&duration[i+1]);
            for(int i=0;i<n;++i)
                scanf("%d",&cost[i+1]);
            int d;
            scanf("%d",&d);
            for(int i=0;i<n;++i)
                start[i+1] = 0;
            for(int i=0;i<d;++i)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                G[a].push_back(b);
                G1[b].push_back(a);
            }
            queue<int> Q;
            for(int i=1;i<n+1;++i)
                if(G1[i].size() == 0)
                    Q.push(i);
            while(!Q.empty())
            {
                int f = Q.front();
                Q.pop();
                for(int i:G[f])
                {
                    start[i] = max(start[i],duration[f] + start[f]);
                    Q.push(i);
                }
            }
            long long int ans = 0;
            for(int i=1;i<n+1;++i)
                ans+=((start[i]+duration[i])*1LL*cost[i]);
            printf("Case No %d: %lld\n",aa,ans);
            aa++;

        }
        return 0;
    }
