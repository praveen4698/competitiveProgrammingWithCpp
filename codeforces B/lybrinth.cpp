#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e3 + 10;
    char A[lim][lim];
    int dist[lim][lim];
    bool visited[lim][lim];
    int n,m;
    int temp[2];
    int  BFS(int x,int y)
    {
        lp(i,1,m+1)
            lp(j,1,n+1)
            {
                dist[i][j] = INF;
                visited[i][j] = false;
            }
        int maxi = 0;
        dist[x][y] = 0;
        queue<pii> Q;
        Q.push(mp(x,y));
        while(!Q.empty())
        {
            pii t = Q.front();
            Q.pop();
            int a = t.F;
            int b = t.S;
            visited[a][b] = true;
            if( dist[a][b] > maxi)
             {
                 maxi = dist[a][b];
                 temp[0] = a;
                 temp[1] = b;
             }
           // printf("yobfs\n");
            if( a-1 > 0 && visited[a-1][b] == false && A[a-1][b] == '.' && dist[a-1][b] > dist[a][b] +1)
            {
                Q.push(mp(a-1,b));
                dist[a-1][b] = dist[a][b] +1;

            }
            if( a+1 <= m && visited[a+1][b] == false && A[a+1][b] == '.' && dist[a+1][b] > dist[a][b] +1)
            {
                Q.push(mp(a+1,b));
                dist[a+1][b] = dist[a][b] +1;

            }
            if( b-1 > 0 && visited[a][b-1] == false && A[a][b-1] == '.' && dist[a][b-1] > dist[a][b] +1)
            {
                Q.push(mp(a,b-1));
                dist[a][b-1] = dist[a][b] +1;

            }
            if( b+1 <= n && visited[a][b+1] == false && A[a][b+1] == '.' && dist[a][b+1] > dist[a][b] +1)
            {
                Q.push(mp(a,b+1));
                dist[a][b+1] = dist[a][b] +1;

            }

        }
        return maxi;
    }

    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            scan2(n,m);
            lp(i,1,m+1)
            {
                scanf("%s",A[i] +1);
            }
            lp(i,1,m+1)
                lp(j,1,n+1)
                {
                    if( A[i][j] == '.')
                    {
                        int y = BFS(i,j);
                        i = n+2;
                        break;
                    }
                }
           // printf("yo\n");
            int maxi = -1;

         //   printf("yo2\n");
             maxi = BFS(temp[0],temp[1]);
          //  printf("yo3\n");
            /*maxi = 0;
            lp(i,1,m+1)
               lp(j,1,n+1)
               {
                   if( dist[i][j] == INF)
                    continue;
                   if( dist[i][j] > maxi)
                        maxi = dist[i][j];

               }*/

         printf("Maximum rope length is %d.\n",maxi);

        }
        return 0;
    }

