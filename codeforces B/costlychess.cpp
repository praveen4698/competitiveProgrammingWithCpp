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
    	struct compare{
			bool operator()(const pair<pii,int> l,const pair<pii,int> r)
			{
				return l.S < r.S;
			}


		};
    int dist[10][10];
    int X[8] = {2,2,1,-1,1,-1,-2,-2};
    int Y[8] = {-1,1,2,2,-2,-2,1,-1};

    int main()
    {
        int x,y,ex,ey;
        while( scanf("%d %d %d %d",&x,&y,&ex,&ey) != EOF)
        {
            lp(i,0,8)
                lp(j,0,8)
                    dist[i][j] = INF;

            priority_queue<pair<pii,int> , vector<pair<pii,int> > , compare> Q;
            Q.push(mp(mp(x,y),0));
            dist[x][y] = 0;
            while(!Q.empty())
            {
                pair<pii,int> t = Q.top();
                int fx = t.F.F;
                int fy = t.F.S;
                int cost = t.S;
                Q.pop();
                lp(i,0,8)
                {
                    int cx = fx + X[i];
                    int cy = fy + Y[i];
                    if( cx >= 0 && cx < 8 && cy >= 0 && cy < 8 )
                    {
                        if( dist[cx][cy] > (cost + cx*fx + cy*fy))
                        {
                            dist[cx][cy] = cost + cx*fx + cy*fy;
                            Q.push(mp(mp(cx,cy),dist[cx][cy]));
                        }
                    }
                }
            }

            if( dist[ex][ey] == INF)
                printf("-1\n");
            else
                printf("%d\n",dist[ex][ey]);

        }

        return 0;
    }
