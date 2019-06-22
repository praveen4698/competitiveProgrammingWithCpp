#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    char G[1001][1001];
    int cont[1001][1001];
    char S[100001];

    int main()
    {
        int n,m,l;
        while(1)
        {
            scanf("%d %d %d",&n,&m,&l);
            if(n == 0 && m == 0 && l == 0)
                break;
            for(int i=0;i<n;++i)
                scanf("%s",G[i]);
            scanf("%s",S);
            int x,y;
            char o;
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j)
                    cont[i][j] = 0;
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    if( G[i][j] != '.' && G[i][j] != '#' && G[i][j] != '*')
                    {
                        o = G[i][j];
                        x = i;
                        y = j;
                    }

                }
            }
           // printf("%d %d %c\n",x,y,o);
            int ans = 0;
            for(int i=0;i<l;++i)
            {
                int px = x;
                int py = y;
                if( o == 'N')
                {
                    if( S[i] == 'E')
                        o='O';
                    else if( S[i] == 'F')
                        x--;
                    else if( S[i] == 'D')
                        o='L';
                }
                else if( o == 'S')
                {
                    if( S[i] == 'E')
                        o = 'L';
                    else if( S[i] == 'F')
                        x++;
                    else if(S[i] == 'D')
                        o = 'O';
                }
                else if(o == 'L')
                {
                    if(S[i] == 'E')
                        o = 'N';
                    else if( S[i] == 'F')
                        y++;
                    else if( S[i] == 'D')
                        o = 'S';
                }
                else
                {
                    if(S[i] == 'E')
                        o = 'S';
                    else if( S[i] == 'F')
                        y--;
                    else if(S[i] == 'D')
                        o = 'N';
                }

                if(x < 0 || x >= n || y < 0 || y >= m)
                {
                    x = px;
                    y = py;
                }
                if(G[x][y] == '#')
                {
                    x = px;
                    y = py;
                }
                if(G[x][y] == '*' && cont[x][y] == 0)
                {
                    ans++;
                    cont[x][y] = 1;

                }
              //  printf("%d %d %c\n",x,y,o);

            }
            printf("%d\n",ans);
        }
        return 0;
    }
