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

set<ll> S;
int main()
{
    ll n;
    cin>>n;
    ll m = sqrt(n) + 1ll;
    for(ll i=1;i<=m;++i){
        if( n%i == 0ll){
            S.insert(n/i);
            S.insert(i);
        }
    }
    cout<<S.size()<<endl;
    return 0;
}
