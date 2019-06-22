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
//ll ans = -1;
ll B,R,C;
const int lim = 101;
ll M[lim],S[lim],P[lim];
vector<ll> ans;
void solve(ll cost,ll b,ll r,ll c)
{
    if( b == 0)
    {
        ans.pb(cost);
        return ;
    }
    if( b < 0 )
        return;
    if( r == 0)
        return ;
    if( c == 0)
        return ;
    for(int i=0;i<=min(M[c],b+1);i++)
    {
        if( i == 0)
            solve(cost,b,c-1,r);
        else
            solve(max(cost,S[c]*1ll*i+1ll*P[c]),b - 1ll*i,c-1ll,r-1ll);
    }

}
int main()
{
    int t;
    scan(t);
    int xx = 1;
    while(t--)
    {
        cin>>R>>B>>C;
        ans.clear();
        for(int i=1;i<C+1;++i)
        {
            cin>>M[i]>>S[i]>>P[i];
        }
        solve(0ll,B,R,C);
        ll ret = INFL;
        for(ll a:ans)
            ret = min(a,ret);
        printf("Case #%d: %lld\n",xx,ret);
        xx++;
    }
    return 0;
}


