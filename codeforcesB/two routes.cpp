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

    int G[401][401],dist[401];
    int main()
    {
        int n,m;
        scan2(n,m);
        lp(i,1,n+1)
            lp(j,1,m+1)
                G[i][j] = 0;

        lp(i,0,n+1)
        {
            dist[i] = INF;
            G[i][i] = -1;
        }
        lp(i,0,m)
        {
            int a,b;
            scan2(a,b);
            G[a][b] = 1;
            G[b][a] = 1;
        }
        int value = 1;
        if( G[1][n] == 1)
            value = 0;
        queue<int> Q;
        Q.push(1);
        dist[1] = 0;
        bool visited[401] = {false};
        while(!Q.empty())
        {
            int father = Q.front();
            Q.pop();
            visited[father ] = true;
            lp(i,1,n+1)
            {
                if(visited[i] == false && G[father][i] == value && dist[i] > dist[father]+1)
                {
                    dist[i] = dist[father] +1;
                    Q.push(i);
                }
            }
        }
        if( dist[n] == INF)
            printf("-1");
        else
            printf("%d",dist[n]);
        return 0;
    }
