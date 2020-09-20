#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
static const int INF = 0x3f3f3f3f;
static const long long int INFL = 0x3f3f3f3f3f3f3f3fLL;
const long long int MOD = 1e9+7;
const long long int  mod = 998244353;


int main()
{
    int t;
    cin>>t;

    vector<vector<vector<int> > > dp(101, vector<vector<int> > (101, vector<int> (2, 0)));
    dp[0][0][1] = dp[0][0][0] = 1;
    for(int i=1;i<101;++i) {
        
        dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
        dp[i][0][1] = dp[i-1][0][0];
        
    }
    for(int i=1;i<101;++i) {
        for(int j=1;j<101;++j) {
            dp[i][j][0] = dp[i-1][j][1] + dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j][0];
            
        }
    } 
    while(t--) {
        int n, k, a;
        cin>>a>>n>>k;
        // vector<vector<vector<int> > > dp(n+1, vector<vector<int> > (k+1, vector<int> (2, 0)));
        int ans = dp[n-1][k][0] + dp[n-1][k][1];
        cout<<a<<" "<<ans<<endl;
    }
    
    return 0;
}
