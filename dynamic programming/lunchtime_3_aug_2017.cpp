#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e2+10;
    int A[lim][lim];
    vector<pair<int,int> >  dp[101][101][257];
    int pro[101][101][257];
    int check(int cx,int cy,int r,int c)
    {
        if( cx >= 0 && cy >= 0 && cy < c && cx < r)
            return 1;
        else
            return 0;
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int r,c,n,sx,sy;
            scanf("%d %d %d",&r,&c,&n);
            scanf("%d %d",&sx,&sy);
            vector<int> dx,dy;
            for(int i=0;i<n;++i)
            {
                int a;
                scanf("%d",&a);
                dx.push_back(a);
            }
            for(int i=0;i<n;++i)
            {
                int a;
                scanf("%d",&a);
                dy.push_back(a);
            }
            for(int i=0;i<r;++i)
                for(int j=0;j<c;++j)
                    scanf("%d",&A[i][j]);

            queue<pair<pair<int,int> ,pair<int,int> > > Q;

            int ans = 0;
            Q.push({{sx,sy},{A[sx][sy],0}});
            dp[sx][sy][0].push_back({sx,sy});
            for(int i=0;i<r;++i)
                for(int j=0;j<c;++j)
                    for(int k=0;k<(1<<n);++k)
                     {
                         //vis[i][j][k] = 0;
                         pro[i][j][k] = 0;
                     }

            while(!Q.empty())
            {
                pair< pair<int,int> ,pair<int,int> > t = Q.front();
                int x = t.first.first;
                int y = t.first.second;
                int profit = t.second.first;
                int mask = t.second.second;
                Q.pop();

                ans = max(ans,profit);
               // if(vis[x][y][mask] == 1)
               //     continue;
               // vis[x][y][mask] =1;
                int mask1 = mask;
                for(int i=0;i<n;++i)
                {
                    mask = mask1;
                    // printf("%d %d\n",(1<<i),mask&(1<<i));
                    if(mask&(1<<i))
                        continue;
                   // printf("x = %d ,y = %d ,profit = %d,mask = %d finall = %d\n",x,y,profit,mask,mask|=(1<<i));
                    int cx = x-dx[i];
                    int cy = y-dy[i];
                    if(check(cx,cy,r,c) == 1)
                    {
                        int flag = 0;
                        for(int kk =0 ; kk<dp[x][y][mask].size();++kk)
                        {
                            if( dp[x][y][mask][kk].first == cx && dp[x][y][mask][kk].second == cy)
                                flag = 1;
                        }
                         if( flag == 0)
                        {
                            if( pro[cx][cy][mask|=(1<<i)] < profit+A[cx][cy])
                            {

                              Q.push({{cx,cy},{profit+A[cx][cy],mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit+A[cx][cy];
                            }
                        }
                        else
                        {

                           if( pro[cx][cy][mask|=(1<<i)] < profit)
                            {

                                Q.push({{cx,cy},{profit,mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit;
                            }
                        }
                    }
                    cx = x+dx[i];
                    cy = y-dy[i];
                    if(check(cx,cy,r,c) == 1)
                    {
                        int flag = 0;
                        for(int kk =0 ; kk<dp[x][y][mask].size();++kk)
                        {
                            if( dp[x][y][mask][kk].first == cx && dp[x][y][mask][kk].second == cy)
                                flag = 1;
                        }
                        if( flag == 0)
                        {
                            if( pro[cx][cy][mask|=(1<<i)] < profit+A[cx][cy])
                            {

                              Q.push({{cx,cy},{profit+A[cx][cy],mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit+A[cx][cy];
                            }
                        }
                        else
                        {

                           if( pro[cx][cy][mask|=(1<<i)] < profit)
                            {

                                Q.push({{cx,cy},{profit,mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit;
                            }
                        }
                    }
                    cx = x-dx[i];
                    cy = y+dy[i];
                    if(check(cx,cy,r,c) == 1)
                    {
                        int flag = 0;
                        for(int kk =0 ; kk<dp[x][y][mask].size();++kk)
                        {
                            if( dp[x][y][mask][kk].first == cx && dp[x][y][mask][kk].second == cy)
                                flag = 1;
                        }
                         if( flag == 0)
                        {
                            if( pro[cx][cy][mask|=(1<<i)] < profit+A[cx][cy])
                            {

                              Q.push({{cx,cy},{profit+A[cx][cy],mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit+A[cx][cy];
                            }
                        }
                        else
                        {

                           if( pro[cx][cy][mask|=(1<<i)] < profit)
                            {

                                Q.push({{cx,cy},{profit,mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit;
                            }
                        }
                    }
                    cx = x+dx[i];
                    cy = y+dy[i];
                    if(check(cx,cy,r,c) == 1)
                    {
                        int flag = 0;
                        for(int kk =0 ; kk<dp[x][y][mask].size();++kk)
                        {
                            if( dp[x][y][mask][kk].first == cx && dp[x][y][mask][kk].second == cy)
                                flag = 1;
                        }
                        if( flag == 0)
                        {
                            if( pro[cx][cy][mask|=(1<<i)] < profit+A[cx][cy])
                            {

                                Q.push({{cx,cy},{profit+A[cx][cy],mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit+A[cx][cy];
                            }
                        }
                        else
                        {

                           if( pro[cx][cy][mask|=(1<<i)] < profit)
                            {

                                Q.push({{cx,cy},{profit,mask|=(1<<i)}});
                                dp[cx][cy][mask|=(1<<i)] = dp[x][y][mask];
                                dp[cx][cy][mask|=(1<<i)].push_back({cx,cy});
                                pro[cx][cy][mask|=(1<<i)] = profit;
                            }
                        }

                    }
                }
            }

            printf("%d\n",ans);
        }
        return 0;
    }
