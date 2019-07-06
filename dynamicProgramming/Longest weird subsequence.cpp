#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int dp[2001][28][28];
    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            string s;
            cin>> s;
            s = "#" + s;
            memset(dp,0,sizeof(dp));
            lp(i,1,27)
                lp(j,1,27)
                    dp[0][i][j] = -10000000;

            lp(k,1,s.length())
            {
                lp(i,0,27)
                {
                    lp(j,0,27)
                    {
                        int x = (int)s[k] - 'a' +1;
                        dp[k][i][j] = max(dp[k][i][j],dp[k-1][i][j]);
                        if( i<= x)
                            dp[k][x][j] = max(dp[k][x][j] ,dp[k-1][i][j] +1);
                        if( j >= x)
                            dp[k][i][x] = max(dp[k][i][x],dp[k-1][i][j] + 1);
                    }
                }
            }

            int ans = -1;
            lp(i,0,27)
                lp(j,0,27)
                    ans = max(ans ,dp[s.length() -1 ][i][j]);

            printf("%d\n",ans);
        }
        return 0;
    }
