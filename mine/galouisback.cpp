#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    char G[1001][1001];
    int X[6] = {-1,-1,0,0,1,1};
    int Y[6] = {0,1,-1,1,-1,0};
    int dir[1001][1001];
    bool vis[1001][1001];
    int r,c;
    queue<pair<int,int> > Q;
    void BFS()
    {
        while(!Q.empty())
        {
            pair<int,int> t = Q.front();
            Q.pop();
            int x = t.first;
            int y = t.second;
            if( vis[x][y] == true)
                continue;
            vis[x][y] = true;
            for(int i=0;i<6;++i)
            {
                int tx = x+X[i];
                int ty = y+Y[i];
              //  printf("%d %d",tx)
                if( tx >= 0 && tx < r && ty < c && ty >= 0 && G[tx][ty] != '.' )
                {
                    //printf("yo\n");
                    if( dir[x][y] == 2 )
                    {
                        dir[tx][ty] = 2;
                        Q.push(make_pair(tx,ty));
                    }
                    else if( (dir[x][y] == 1 && dir[tx][ty] == 1) || (dir[x][y] == -1 && dir[tx][ty] == -1) )
                    {
                        dir[tx][ty] = 2;
                        dir[x][y] = 2;
                        Q.push(make_pair(tx,ty));
                        Q.push(make_pair(x,y));
                        vis[x][y] = false;
                    }
                    else if( dir[x][y] == 1 && dir[tx][ty] == 0)
                    {
                        dir[tx][ty] = -1;
                        Q.push(make_pair(tx,ty));
                    }
                    else if( dir[x][y] == -1 && dir[tx][ty] == 0)
                    {
                        dir[tx][ty] = 1;
                        Q.push(make_pair(tx,ty));
                    }
                }
            }
        }
        return ;
    }
    int main()
    {
        while(1)
        {
            scanf("%d %d",&r,&c);
            if( r == 0 || c == 0)
                break;
            for(int i = 0;i<r;++i)
                scanf("%s",G[i]);
            for(int i=0;i<r;++i)
            {
                for(int j=0;j<c;++j)
                {
                    vis[i][j] = false;
                    dir[i][j] = 0;
                    if(G[i][j] == 'I')
                    {
                        Q.push(make_pair(i,j));
                        dir[i][j] = 1;
                    }
                }
            }
            BFS();
            putchar('\n');
            for(int i=0;i<r;++i)
            {
                for(int j=0;j<c;++j)
                {
                    if( G[i][j] == '.')
                        printf(".");
                    else if(dir[i][j] == 1)
                        printf("(");
                    else if( dir[i][j] == -1)
                        printf(")");
                    else if( dir[i][j] == 2)
                        printf("B");
                    else if( dir[i][j] == 0)
                        printf("F");
                }
                printf("\n");
            }
           // printf("\n");

        }
        return 0;
    }
