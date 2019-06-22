#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    long long dis[lim];
    bool vis[lim];
    vector<pair<int,long long int > > G[lim];
    struct comp
    {
        bool operator() (const pair<int,long long int>& lhs, const pair<int,long long int> & rhs) const
            {return lhs.second>rhs.second;}
        };
    void dijkstra()
    {
        dis[1] = 0;
        priority_queue<pair<int,long long int> , vector<pair<int,long long int> >, comp > Q;
        Q.push(make_pair(1,0*1LL));
        while(!Q.empty())
        {
            pair<int,long long int> t = Q.top();
            int father = t.first;
            long long int distance = t.second;
           // printf("%d %d\n",father,distance);
            if(vis[father] == true)
                continue;
            vis[father] = true;
            Q.pop();
            for(auto it:G[father])
            {
                if(dis[it.first] > it.second+distance)
                {
                    dis[it.first] = it.second+distance;
                    Q.push(make_pair(it.first,dis[it.first]));
                }
            }
        }
    }

    int main()
    {
        memset(dis,INFL,sizeof(dis));
        memset(vis,false,sizeof(vis));
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<m;++i)
        {
            int a,b;
            int c;
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back(make_pair(b,1LL*c));
            G[b].push_back(make_pair(a,1LL*c));
        }
        dijkstra();
        int cont = 0;
        for(int i=0;i<k;++i)
        {
            int a;
            int c;
            scanf("%d %d",&a,&c);
            c = 1LL*c;
            if( dis[a] <= c)
                cont++;
            else
                dis[a] = c;

        }
        printf("%d",cont);
        return 0;
    }
