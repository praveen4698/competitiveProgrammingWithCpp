#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int dx[] = {-1,0,1,-1,1,-1,0,1};
    int dy[] = {-1,-1,-1,0,0,1,1,1};
    const int lim = 501;
    int G[lim][lim],dis[lim][lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,m;
            scanf("%d %d",&n,&m);
            int maxi = -1;
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    scanf("%d",&G[i][j]);
                    dis[i][j] = INF;
                    if( G[i][j] > maxi)
                        maxi = G[i][j];
                }
            }
            queue<pair<int,int> > Q;
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    if(G[i][j] == maxi)
                    {
                        dis[i][j] = 0;
                        Q.push(make_pair(i,j));
                    }
                }
            }
            while(!Q.empty())
            {
                pair<int,int> t = Q.front();
                Q.pop();
                int x = t.first;
                int y = t.second;
                for(int i=0;i<8;++i)
                {
                    int cx = x+dx[i];
                    int cy = y+dy[i];
                    if( cx >= 0 && cx <n && cy >= 0 && cy < m && dis[cx][cy] > (dis[x][y] + 1))
                    {
                        dis[cx][cy] = dis[x][y] + 1;
                        Q.push(make_pair(cx,cy));
                    }
                }
            }
            int ans = -1;
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j)
                    if( ans < dis[i][j])
                        ans = dis[i][j];
            printf("%d\n",ans);
        }
        return 0;
    }
