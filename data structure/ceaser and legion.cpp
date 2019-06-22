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
    const int mod = 1e9 + 7;
    int dp[101][101][2];
    int k1,k2;
    int DP(int n1,int n2,int start)
    {
        if( n1 < 0 && n2 < 0)
            return 0;
        if( n1 == 0 && n2 == 0)
            return 1;
        if( n2 == 0 && start == 1)
            return 0;
        if( n1 == 0 && start == 0)
            return 0;
       // if( n1 == 0 || n2 == 0)
        //    return dp[n1][n2][start] = 1;
        if( dp[n1][n2][start] != -1)
            return dp[n1][n2][start];
        if( start == 0)
        {
            ll ans = 0;
            lp(i,1,k1+1)
            {
                if( n1 - i < 0)
                    break;
                ans = ans + DP(n1-i,n2,1);
                ans = ans%mod;

            }
            dp[n1][n2][start] = (int)ans;
            return dp[n1][n2][start];
        }
        else
        {
            ll ans = 0;
            lp(i,1,k2+1)
            {
                if( n2 - i < 0)
                    break;
                ans = ans + DP(n1,n2-i,0);
                ans = ans%mod;

            }
            dp[n1][n2][start] = (int)ans;
            return dp[n1][n2][start];

        }
    }


    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            int n1,n2;
            scan2(n1,n2);
            scan2(k1,k2);
            lp(i,0,n1+1)
                lp(j,0,n2+1)
                {
                    dp[i][j][0] = dp[i][j][1] = -1;
                }

            printf("%d\n",(DP(n1,n2,0)+DP(n1,n2,1))%mod);
        }
        return 0;
    }


