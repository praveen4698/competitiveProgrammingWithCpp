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
typedef __int128 INT;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9+7;
const ll MOD = 1e9+7;

// const ll mod = 998244353;
const int lim = 1e5+10;
vector<INT> di[lim];
inline ll power(ll a, ll b){
	ll x = 1ll%mod;
	while(b){
		if(b&1) x = (x*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return x;
}
int main()
{
    for(int i=2;i<lim;++i){
        for(int j=i;j<lim;j+=i)
            di[j].push_back(i);
    }

    int t;
    scan(t);
    while(t--){
        ll l,r,k;
        scanf("%lld %lld %lld",&l,&r,&k);
        ll ans = 0;
        for(int i=l;i<=r;++i){
            ll temp = k;
            temp%=MOD;
            temp++;
            temp%=MOD;
            for(int j:di[i]){

                ll t = power((ll)j,k+1) - 1;
                // cout<<t<<endl;
                if( t < 0)
                    t+=MOD;
                ll t2 = power((ll)j-1,MOD-2);
                // cout<<t2<<endl;
                temp+=(t*t2)%MOD;
                temp%=MOD;
                if( temp<0)
                    temp+=MOD;
            }
            ans+=temp;
            ans%=MOD;
            // cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}
