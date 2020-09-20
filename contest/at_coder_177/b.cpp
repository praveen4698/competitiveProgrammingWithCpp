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
    string S, T;
    cin>>S;
    cin>>T;
    int n = S.size();
    int m = T.size();

    int ans = INT_MAX;
    for(int i=m-1;i<n;++i) {
        int j = i-m+1;
        int count = 0;
        for(int k=0; k<m; ++k) {
            if( S[k+j] != T[k])
                count++;
        }
        ans = min(ans, count);

    }
    cout<<ans<<endl;
    return 0;
}
