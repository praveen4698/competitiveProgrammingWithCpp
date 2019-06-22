#include<bits/stdc++.h>
using namespace std;
int qq;
vector<pair<int,int> >  G[100001];
int dist[100001];
int pos[100001];
set<pair<int,int> > Q;
int Sp[100001];
    inline int gt(int x)
    {
        if( pos[x] < qq)
            dist[x] = 1e9;
        pos[x] = qq;
        return dist[x];
    }
    inline void up(int x,int y)
    {
        pos[x] = qq;
        dist[x] = y;
    }


    int main()
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        qq = 0;
        for(int i = 0;i<k;++i)
        {
            int x;
            scanf("%d",&x);
            Sp[x] = 1;
        }
        for(int i =0;i<m;++i)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back(make_pair(b,c));
            G[b].push_back(make_pair(a,c));
        }
        int ans = 1e9+11;
        for(int i = 1;i<=n;++i)
        {
            if(Sp[i] != 1)
                continue;
            qq++;
            up(i,0);
            Q.clear();
            Q.insert(make_pair(0,i));
            int cn = 0;
            while(!Q.empty())
            {
                if(ans < Q.begin()->first)
                    break;
                int fhr = Q.begin()->second;
                Q.erase(Q.begin());
                if( Sp[fhr])
                {
                    cn++;
                    if(cn > 1)
                    {
                        ans = min(ans,gt(fhr));
                        break;
                    }
                }

                for(int j = 0;j < G[fhr].size();++j)
                {
                    int child = G[fhr][j].first;
                    int dis = G[fhr][j].second;
                    if(gt(fhr) + dis < gt(child))
                    {
                        Q.erase(make_pair(gt(child),child));
                        up(child,gt(fhr) + dis);
                        Q.insert(make_pair(gt(fhr) + dis,child));
                    }
                }


            }
        }
        printf("%d",ans);
        return 0;
    }
