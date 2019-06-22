#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 51;
    char G[lim][lim];
    bool visit[lim][lim];
    long long int n,ans;
    map<char,int> M;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    int cont = 0;
    void DFS(int i,int j)
    {
        visit[i][j] = true;
        M[G[i][j]]++;
        cont++;
      //  printf("%d %d\n\n\n\n",i,j);
        for(int k=0;k<4;++k)
        {
            int x = i+dx[k];
            int y = j+dy[k];
         //   printf("%d %d\n",x,y);
         //   printf("%d %d %d %c\n",min(x,y), max(x,y)  , visit[x][y] , G[x][y]);
            if( min(x,y) >= 0 && max(x,y) < n && visit[x][y] == false && G[x][y] != '.' )
            {
            //    printf("yo = %d %d\n",x,y);
                 DFS(x,y);


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
                scanf("%s",G[i]);
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    visit[i][j] = false;
            ans = 1LL;
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(visit[i][j] == false && G[i][j] != '.')
                    {
                        M.clear();
                        cont = 0;
                        DFS(i,j);
                       // printf("? = %d,B =  %d,G =%d,P =  %d\n",M['?'],M['B'],M['G'],M['P']);
                        if(cont == 1 && M['?'] == 1)
                            ans = (3LL*ans)%mod;
                        else if(cont > 1 && M['G'] > 0)
                            ans = (ans*0LL)%mod;
                        else if(cont > 1 && M['B'] > 0 && M['P'] > 0)
                            ans = (ans*0LL)%mod;
                        else if( cont == M['?'])
                            ans = (2LL*ans)%mod;
                    }
                }
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
