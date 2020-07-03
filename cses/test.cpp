#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;

string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int> > DP(n, vector<int> (n, 0));
        int left = 0;
        int right = 0;
        int ans = 1;
        for( int i=0;i<n;++i) {
            DP[i][i] = 1;
             DP[i][i] = 1;
            if (i != n-1 && s[i] == s[i+1]){
                DP[i][i+1] = 2;
            }
            else if(i != n-1){
                DP[i][i+1] = 0;
            }
            if (i != n-1 && DP[i][i+1] > ans) {
                    ans = DP[i][i+1];
                    left = i;
                    right = i+1;
                }
        }
        
        for(int i=3;i<n+1;++i) {
           
            for(int j=i-1;j<n;++j) {
                
                int lower_end = j-i+1;
                // cout<<lower_end<<j<<endl;
                if( s[lower_end] == s[j] and DP[lower_end+1][j-1] == (j-lower_end-1)){
                    DP[lower_end][j] = j-lower_end +1;
                    // cout<<s[i]<<s[j]<<endl;
                    // return to_string(i);
                }
                else
                    DP[lower_end][j] = 0;
                if (DP[lower_end][j] > ans) {
                    ans = DP[lower_end][j];
                    left = lower_end;
                    right = j;
                }
            }
        }
        // cout<<left<<right<<endl;
        return s.substr(left, ans);
}
int main() {
    printf(" hi there");
    long long int sum[1000000];
    memset(sum, 0ll, sizeof(sum));
    vector<long long int> A;
    int n, q;
    scanf("%d %d", &n, &q);
    sum[0] = 0ll;
    for(int i=1;i<=n;++i){
        long long int a;
        cin>>a;
        if( i == 0) {
            sum[i] = a;
        }
        else {
            sum[i] = sum[i-1] + a;
        }
    }
    while(q--) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", sum[b] - sum[a-1]);
    }
    return 0;
}