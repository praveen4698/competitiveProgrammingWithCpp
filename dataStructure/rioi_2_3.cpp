#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    bool reach[51][51];
    int cost[51][51];
    int sx,sy,ex,ey,n;
    int X[4] = {-1,1,0,0};
    int Y[4] = {0,0,-1,1};
    void BFS(int dis)
    {
        queue<pair<int,int> > Q;
        Q.push(make_pair(sx,sy));
        reach[sx][sy] = true;
        while(!Q.empty())
        {
            pair<int,int> t= Q.front();
            int fx = t.first;
            int fy = t.second;
            Q.pop();

            for(int i=0;i<4;++i)
            {
                int cx = fx + X[i];
                int cy = fy + Y[i];
              //  printf("%d ",&n);
                if( cx >= 0 && cx < n && cy >= 0 && cy < n)
                {
                    //if(dis == 15)
                       // printf("%d %d %d\n",dis,cx,cy);
                    if(dis&(1<<cost[cx][cy]) && ( reach[cx][cy] == false))
                    {
                         Q.push(make_pair(cx,cy));
                         reach[cx][cy] = true;

                    }

                }
            }
        }
    }

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {

            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    scanf("%d",&cost[i][j]);
                }
            }
            int ans = 11;
            scanf("%d %d",&sx,&sy);
            scanf("%d %d",&ex,&ey);
            for(int i=1;i<=1024;++i)
            {
                if(i&(1<<cost[sx][sy]))
                {
                 //   printf("in ");
                    memset(reach,false,sizeof(reach));
                    BFS(i);
                   // printf("%d %d\n",i,reach[ex][ey]);
                 //   printf("out\n");

                if(reach[ex][ey] == true )
                {
                    int cont = 0;

                    for(int j=0;j<10;j++)
                    {
                        if(i&(1<<j))
                            cont++;
                    }
                 //   printf("%d i = %d\n",cont,i);
                    ans =  min(ans,cont);
                }
                }
            }
            printf("%d\n",ans);
        }

        return 0;
    }
