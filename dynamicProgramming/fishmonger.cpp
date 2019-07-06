#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
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

    int toll[101][101];
    int dist[101][101];
    int dp[101][1001];
    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            int n,t;
            scan(n);
            scan(t);
            //if( n == 0 && t == 0)
              //  break;
            lp(i,1,n+1)
                lp(j,1,n+1)
                    scan(dist[i][j]);
            lp(i,1,n+1)
                lp(j,1,n+1)
                    scan(toll[i][j]);
            lp(i,0,n+1)
                lp(j,0,t+1)
                    dp[i][j] = INF;
            lp(i,0,t+1)
                dp[1][i] = 0;
            lp(tim,0,t+1)
                lp(cit,1,n+1)
                    lp(mid,1,n+1)
                    {
                        if(mid == cit) continue;
                        if( dist[mid][cit] > tim) continue;
                        dp[cit][tim] = min(dp[cit][tim], toll[mid][cit] + dp[mid][tim - dist[mid][cit]]);

                    }

            if( dp[n][t] == INF)
                printf("-1\n");
            else
            {
                int travel = 0;
                lp(i,0,t+1)
                    if( dp[n][i] == dp[n][t])
                      {

                        travel = i;
                        break;
                      }
                printf("%d %d\n",dp[n][t],travel);
            }
        }

        return 0;
    }

