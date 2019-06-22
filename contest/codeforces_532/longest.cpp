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

const int lim = 1e6+10;
vector<ll> A;
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        ll a;
        cin>>a;
        A.push_back(a);
    }
    sort(all(A));
    reverse(all(A));
    ll sum = k*A[0] + A[1];
    ll ans = (m/(k+1))*sum  + (m%(k+1))*A[0];
    cout<<ans<<endl;
    return 0;
}
