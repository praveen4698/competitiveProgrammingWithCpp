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

    const ll mod = 1e9+7;
    int main()
    {
        ll n,arr[30],l=0,dp[1001],dp2[1001];
        string s;
        cin>>n>>s;
        lp(i,0,26)
            cin>>arr[i];

        dp[0] = 1;
        dp2[0] = 0;
        lp(i,1,n+1)
        {
            ll f = 0;
            dp2[i] = n;
            lpr(x,i-1,0)
            {
                f = max(f,i - arr[s[x]-'a']);
                if( f > x)
                    continue;

                dp[i] = dp[i]+dp[x];
                dp[i] = dp[i]%mod;
                dp2[i] = min(dp2[i] ,1 + dp2[x]);
                l = max(l,(ll)i-x);

            }
        }
        cout<<dp[n]<<"\n"<<l<<"\n"<<dp2[n];
        return 0;
    }


