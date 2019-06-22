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
    ll ans = 0;
    ll n,m;
    cin>>n>>m;
    for(ll i=1; i<=m; ++i){
        for(ll j=1; j<=m; ++j){

            ll t = ( i*1ll*i + 1ll*j*j )%m;
            if( t == 0){
                ans+=(n/m)*(n/m);
                if( n%m>= i%m && i%m != 0)
                    ans+=(n/m);
                if( n%m >= j%m && j%m != 0)
                    ans+=(n/m);
                if( n%m>= i%m && n%m >= j%m && i%m != 0 && j%m != 0)
                    ans++;
            } 
        }
    }    
    cout<<ans<<endl;
    return 0;
}
