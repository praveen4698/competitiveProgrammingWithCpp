#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
ll A[lim],B[lim],D[lim];
vector<pair<ll,ll> > G;
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,k;
        scanf("%lld %lld",&n,&k);
        G.clear();
        for(int i=0;i<n;++i)
            cin>>A[i];
        for(int i=0;i<n;++i)
            cin>>D[i];
        for(int i=0;i<n;++i)
            G.pb({A[i],D[i]});
        for(int i=0;i<k;++i)
            cin>>B[i];
        sort(all(G));
        ll lo = 1ll;
        ll hi = 0ll;
        for(int i=0;i<n;++i)
            hi = hi + 1ll*D[i];
        for(int i=0;i<k;++i)
        {
            if( i%2 == 0)
            {
                lo = hi - 1ll*B[i] + 1ll;
            }
            else
                hi = lo + 1ll*B[i] - 1ll;

        }
        ll ans = 0ll;
        ll temp = 0ll;
       // cout<<lo<<" "<<hi<<endl;
        for(int i=0;i<n;++i)
        {
            ll a = 1ll*G[i].fi;
            ll d = 1ll*G[i].se;
            ll sum = temp + d;
//cout<<sum<<endl;
            if(sum < lo)
            {
                temp = sum;
                continue;
            }
            if( sum >= lo && temp < lo)
            {
                ans = ans + (sum-lo+1)*1ll*a;
            }
            else
            {
                ans = ans + (d)*1ll*a;
            }
            if(sum > hi)
            {
                ans = ans - (sum-hi)*1ll*a;
            }
            temp = sum;
            if( sum > hi)
                break;



        }
        cout<<ans<<endl;
    }
    return 0;
}


