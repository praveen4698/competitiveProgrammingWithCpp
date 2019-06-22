#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printfn("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
vector<ll> A,B;
ll m,n;
bool solve(ll x){
    ll M = m;
   // cout<<"FSD"<<endl;
    for(int i=0;i<n;++i){
       if( A[i]*1ll*B[i] <= x)
            continue;
       ll tt = (A[i]*1ll*B[i] - 1ll*x)/B[i];
       if((A[i]*1ll*B[i] - 1ll*x)%B[i] != 0 )
            tt++;
       //cout<<tt<<"  FSDF"<<endl;
       if( M < tt)
            return false;
       M = M - tt;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    A.resize(n);
    B.resize(n);
    for(int i=0;i<n;++i)
        cin>>A[i];
    for(int i=0;i<n;++i)
        cin>>B[i];
    ll lo = 0ll,hi = 1e18;
    ll ans = 0ll;
    while(lo<hi){
        ll mid = (lo+hi)/2;
       // cout<<lo<<" " <<hi<<endl;
        if( solve(mid) ){
            hi = mid;
           // cout<<mid<<endl;
        }
        else
            lo = mid+1;
    }
    cout<<lo<<endl;
    return 0;
}


