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
    const ll mod = 1e9 + 7;
    const int lim = 2e3;
    ll ans[lim],dp[lim][lim];
    int main()
    {
        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[2][2] = 1;
        lp(i,1,1001)
            dp[i][1] = 1;
        lp(i,3,1001)
        {
            lp(j,2,i+1)
            {
                dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1])%mod;
            }
        }
        lp(i,1,1001)
            lp(j,1,i+1)
                ans[i] = (ans[i] + dp[i][j])%mod;
        int t;
        scan(t);
        while(t--)
        {
            int n;
            scan(n);
            printf("%lld\n",ans[n]);
        }
        return 0;
    }
