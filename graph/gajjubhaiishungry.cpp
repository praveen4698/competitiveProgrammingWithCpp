#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6 + 10;
    int dist[lim];
    vector<int> G[lim],R;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,m;
            scanf("%d %d",&n,&m);
            R.clear();
            for(int i = 0; i<=n;++i)
             {
                 G[i].clear();
                 dist[i] = INF;
             }
            for(int i = 0;i<n-1;++i)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                G[b].push_back(a);
                G[a].push_back(b);
            }
            for(int i=0;i<m;++i)
            {
                int a;
                scanf("%d",&a);
                R.push_back(a);
            }
            dist[1] = 0;
            queue<int> Q;
            Q.push(1);
            vector<int>::iterator it;
            while(!Q.empty())
            {
                int prt = Q.front();
                Q.pop();

                for(it = G[prt].begin();it!=G[prt].end();++it)
                {
                    int child = *it;
                    if( dist[child] > dist[prt] + 1)
                    {
                        dist[child] = dist[prt] + 1;
                        Q.push(child);
                    }
                }
            }

            long long int ans=0;
            for(it = R.begin();it != R.end();++it)
                ans+=(2*dist[*it]);

            double res = (double)ans/m;
            printf("%.8f\n",res);
        }
        return 0;
    }
