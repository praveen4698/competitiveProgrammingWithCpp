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

const int lim = 1e3+10;
ll A[lim];
ll p,n;
bool check(ll x){
    ll cont = 0;
    for(int i=0;i<n;++i){
        cont = cont + x/A[i] + 1;
    }
    // cout<<x<<" "<<cont<<endl;
    return cont >= p;
}
int main()
{ 
    int t;
    scan(t);
    while(t--){
        cin>>n>>p;
        for(int i=0;i<n;++i){
            cin>>A[i];
        }       
        ll hi = 1e18;
        ll ans = -1;
        ll lo = 1;
        while(hi >= lo){
            ll mid = (hi+lo+1)/2;
            // cout<<lo<<" "<<hi<<" "<<mid<<endl;
            if( check(mid) ){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid +1;
            }
        }
        // cout<<ans<<endl;
        ll cont = 0;
        for(int i=0;i<n;++i){
            cont = cont + ans/A[i] + 1;
        }
        int ret = -1;
        for(int i=n-1;i>=0;--i){
            if( ans%A[i] == 0 && cont > p ){
                cont--;
            }
            else if( ans%A[i] == 0 && cont == p){
                ret = i+1;
                break;
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
