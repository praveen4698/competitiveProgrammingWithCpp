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

string A,B;
vector<ll> sum;
int main()
{
    int n,m;
    scan2(n,m);
    cin>>A;
    cin>>B;
    for(int i=0;i<m;++i){
        ll a = 1ll*(B[i]-'0');
        if( i >0)
            sum.push_back(a+sum[i-1]);
        else
            sum.push_back(a);
    }
    ll prev = 1;
    ll ans = 0;
    int j = m-1;
    for(int i=n-1;i>=0;--i){
        if( A[i] == '1'){
            ans = ans + prev*sum[j];
            ans%=mod;
        }
        // cout<<ans<<endl;
        prev*=2;
        j--;
        if( j < 0)
            break;
        prev%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
