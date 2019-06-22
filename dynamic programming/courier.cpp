#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int G[101][101];
    int dp[4096][101];
    pair<int,int> A[13];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,m,start;
            scanf("%d %d %d",&n,&m,&start);
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    G[i][j] = INF;
                }
                G[i][i] = 0;
            }
            for(int i=0;i<m;++i)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                G[a][b] = c;
                G[b][a] = c;
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    for(int k=1;k<=n;++k)
                    {
                        G[j][k] = min(G[j][k],G[j][i]+G[i][k]);
                    }
                }
            }
        /*    for(int i=1;i<=n;++i)
          {

                for(int j=1;j<=n;++j)
            {
                printf("%d",G[i][j]);
            }
            printf("\n");
          }*/
            int z;
            scanf("%d",&z);
            int cont = 0;
            for(int i=0;i<z;i++)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                for(int j=0;j<c;j++)
                {
                    A[cont].first = a;
                    A[cont].second = b;
                    cont++;
                }
            }

            int lim = 1<<cont;
            for(int i=0;i<lim;++i)
                for(int j=0;j<=n;++j)
                    dp[i][j] = INF;
            dp[0][start] = 0;

           // printf("lim = %d\n",lim);
            for(int i=0;i<lim;++i)
            {
                for(int j=0;j<cont;j++)
                {
                   // printf("%d\n",(1<<j));
                    if( (i&(1<<j)) == 0)
                       {
                         //  printf("j= %d\n",j);
                           for(int k=1;k<=n;++k)
                            {
                                dp[i|(1<<j)][A[j].second] = min(dp[i|(1<<j)][A[j].second],dp[i][k]+G[k][A[j].first]
                                                                +G[A[j].first][A[j].second]);
                            }
                       }
                }
            }
            int ans = INF;
            for(int i=1;i<=n;++i)
             {
                 ans = min(dp[lim-1][i] + G[i][start],ans);
               //  printf("%d\n",dp[lim-1][i]);
             }

            printf("%d\n",ans);
        }
        return 0;
    }
