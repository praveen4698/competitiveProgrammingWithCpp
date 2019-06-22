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


int main()
{
    ll n,m;
    cin>>n>>m;
    ll ans1 = -1ll;
    ll t = n%2ll + n/2ll;
    ans1 = max(0ll, n - 2*m);
    ll nn = n*1ll*(n-1)/2;
    ll ans2 = -1;
    if( m == 0){
        ans2 = n;
    }
    else if( m == nn ){
        ans2 = 0;
    }
    else{
        for(int i=0;i<=n;++i){
            nn = (i)*1ll*(i-1)/2;
            if( nn >= m){
                ans2 = n-i;
                break;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
