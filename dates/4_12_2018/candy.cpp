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
const ll mod = 1e9+7;
const ll MOD = 998244353;
vector<ll> A;
void solve(ll t,ll &sum,ll &cont){

    for(int i=0;i<A.size();++i){
        if( t >= A[i] ){
            t-=A[i];
            sum+=A[i];
            cont++;

        }
    }
    

}
int main()
{
    int n;
    ll t;
    scanf("%d %lld",&n,&t);
    ll mini = INFL;
    A.resize(n);
    for(int i=0;i<n;++i){
        cin>>A[i];
        mini = min(mini,A[i]);
    }
    ll ans = 0;
    while(t>=mini){
        ll sum = 0;
        ll cont = 0;
        solve(t,sum,cont);
        ans += cont*(t/sum);
        t%=sum;

    }
    cout<<ans<<endl;
    return 0;
}
