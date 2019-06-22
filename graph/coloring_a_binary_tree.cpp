#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e4 + 10;
    int dpx[3][lim],dpn[3][lim],child,n;
    char G[lim];
    void DFS()
    {
        int p = child;
        if(G[p] == '0')
        {
            for(int i=0;i<3;++i)
            {
                dpx[i][p] = 0;
                dpn[i][p] = 0;
            }
            dpx[0][p] = 1;
            dpn[0][p] = 1;
            return ;
        }
        if( G[p] == '1')
        {
            child++;
            int c1 = child;
            DFS();

            dpx[0][p] = 1 + max(dpx[1][c1],dpx[2][c1]);
            dpx[1][p] = max(dpx[0][c1],dpx[2][c1]);
            dpx[2][p] = max(dpx[0][c1],dpx[1][c1]);

            dpn[0][p] = 1 + min(dpn[1][c1],dpn[2][c1]);
            dpn[1][p] = min(dpn[0][c1],dpn[2][c1]);
            dpn[2][p] = min(dpn[0][c1],dpn[1][c1]);
            return;

        }
        else if( G[p] == '2')
        {
            child++;
            int c1 = child;
            DFS();
            child++;
            int c2 = child;
            DFS();

            dpx[0][p] = 1 + max(dpx[1][c1]+dpx[2][c2],dpx[2][c1]+dpx[1][c2]);
            dpx[1][p] = max(dpx[0][c1]+dpx[2][c2],dpx[2][c1]+dpx[0][c2]);
            dpx[2][p] = max(dpx[0][c1]+dpx[1][c2],dpx[1][c1]+dpx[0][c2]);


            dpn[0][p] = 1 + min(dpn[1][c1]+dpn[2][c2],dpn[2][c1]+dpn[1][c2]);
            dpn[1][p] = min(dpn[0][c1]+dpn[2][c2],dpn[2][c1]+dpn[0][c2]);
            dpn[2][p] = min(dpn[0][c1]+dpn[1][c2],dpn[1][c1]+dpn[0][c2]);
            return;
        }

    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s",G);
            n = strlen(G);
            child = 0;

            for(int i=0;i<n+1;++i)
            {
                dpx[0][i] = -1;
                dpx[1][i] = -1;
                dpx[2][i] = -1;
                dpn[0][i] = INF;
                dpn[1][i] = INF;
                dpn[2][i] = INF;
            }
            DFS();
            int ans1 = max(max(dpx[0][0],dpx[1][0]),dpx[2][0]);
            int ans2 = min(min(dpn[0][0],dpn[1][0]),dpn[2][0]);
            printf("%d %d\n",ans1,ans2);
        }
        return 0;
    }
