#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9+7;
const ll mod = 998244353;


int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<vector<long long int> > dp(n, vector<long long int> (m, 1e17));
        vector<vector<long long int> > cost(n, vector<long long int> (m, 0));
        vector<vector<long long int> > discount(n, vector<long long int> (m, 0));

        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>cost[i][j];

        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>discount[i][j];

        long long int mini = 0ll;
        for(int i=0;i<n;++i) {
            // i -> items
            // j -> shops
            for(int j=0;j<m;++j) {
                if( i == 0)
                    dp[i][j] = cost[i][j];
                else
                    dp[i][j] = min(cost[i][j] + mini, max(cost[i][j]-discount[i-1][j], 0ll) + dp[i-1][j]);
            }
            mini = 1e18;
            for(int j=0;j<m; ++j)
                mini = min(mini, dp[i][j]);
        }
        cout<<mini<<endl;
        
    }
    return 0;
}
