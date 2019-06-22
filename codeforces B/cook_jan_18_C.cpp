#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
int dp[60][60];
int dp2[60][60];

int main()
{
    memset(dp,-INF,sizeof(dp));
    memset(dp2,-INF,sizeof(dp2));
    int n,k;
    scan2(n,k);
    for(int i=1;i<=n;++i)
    {
        int a;
        scan(a);
        if( i == 1)
            dp2[a][0] = 1;
        else
        {
            for(int j=0;j<51;++j)
            {
                //for(int cost = 0 ;cost < abs(a-j);cost++)
                //    dp[i][a][cost] = dp[i-1][a][cost];
                for(int cost=abs(a-j);cost<51;cost++)
                {
                    dp2[a][cost] = max(max(dp2[a][cost],dp[a][cost]),1 + dp[j][cost-abs(a-j)]);
                }
                for(int cost = 0 ;cost<51;++cost)
                    dp2[j][cost] = max(dp2[j][cost],dp[j][cost]);
            }
        }
        for(int j=0;j<51;++j)
            for(int k=0;k<51;++k)
                dp[j][k] = dp2[j][k];
        memset(dp2,-INF,sizeof(dp2));
    }
    /*for(int i=1;i<=n;++i)
    {
        for(int j=0;j<5;++j)
        {
            for(int k=0;k<5;++k)
            {
                cout<<dp[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    } */
    int ans = 0;
    for(int i=0;i<51;++i)
    {
        for(int j=0;j<k+1;++j)
        {
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

