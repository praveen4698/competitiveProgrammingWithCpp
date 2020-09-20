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
    int n;
    cin>>n;
    vector<long long int> A;
    long long int sum  = 0;
    long long int ans = 0;
    for(int i=0;i<n;++i) {
        long long int a = 0;
        cin>>a;
        ans = ans + (a*sum)%MOD;
        ans = ans%MOD;
        sum += a;
        sum  %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}
