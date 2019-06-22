#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 501;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    char G[lim][lim];
    int visit[lim][lim];
    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%s",G[i]);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(G[i][j] == 'X')
                    visit[i][j] = 1;
                else
                    visit[i][j] = 0;
            }
        }
        int x,y,ex,ey;
        scanf("%d %d",&x,&y);
        scanf("%d %d",&ex,&ey);
        queue<pair<int,int> > Q;
        visit[x-1][y-1] = 1;
        Q.push(make_pair(x-1,y-1));
        while(!Q.empty())
        {
            pair<int,int> t = Q.front();
            Q.pop();
            int x1 = t.first;
            int y1 = t.second;
            for(int i=0;i<4;++i)
            {
                int x = x1+dx[i];
                int y = y1+dy[i];
                if( x>=0 && x<n && y>=0 && y<m && visit[x][y] == 0)
                {
                    Q.push(make_pair(x,y));
                    visit[x][y] = 1;
                }
                else if( x>=0 && x<n && y>=0 && y<m && visit[x][y] == 1)
                {
                    visit[x][y] = 2;
                }
            }

        }
        printf("%d \n",visit[ex-1][ey-1]);
        if(visit[ex-1][ey-1] == 2)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }
