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
#define MOD 100000000
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int n;
    int dp[100001][2];
    vpii arr(100001);
    void solve()
    {
        memset(dp,0,sizeof(dp[0][0])*100001*2);
        dp[0][1] = 1;
        vi endtime;
        endtime.pb(arr[0].F);
        lp(i,1,n)
        {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            if(dp[i][0] >= MOD)
                dp[i][0]-=MOD;
            if( arr[i].second < endtime[0])
            {
                dp[i][1] =1  ;
            }
            else
            {
                vi::iterator it;
                it = upper_bound(endtime.begin(),endtime.end(),arr[i].S);
                int di = it-endtime.begin();
                di = di-1;
                dp[i][1] = 1+ dp[di][1] + dp[di][0];
                if(dp[i][1] >= MOD)
                    dp[i][1]-=MOD;
            }
            endtime.pb(arr[i].F);
        }
        printf("%0.8d\n",(dp[n-1][0] + dp[n-1][1])%MOD);
    }
    int main()
    {
        while(1)
        {
            scan(n);
            if( n == -1)
                break;
            lp(i,0,n)
            {
                int a,b;
                scan(a);

                scan(b);
                arr[i].F = b;
                arr[i].S = a;
            }
            sort(arr.begin(),arr.begin()+n);
            solve();
        }
        return 0;
    }
