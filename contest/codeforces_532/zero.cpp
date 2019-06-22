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

const int lim = 1e7;
int P[lim];
vector<int> primes;
void preprocess(){
    memset(P,0,sizeof(P));
    for(int i=2;i<lim;++i){
        if(P[i] == 0){
            for(int j=i;j<lim;j=j+i)
                P[j] = i;
        }
    }
    for(int i=2;i<lim;++i)
        if(P[i]==i)
            primes.push_back(i);
}
int main()
{
    preprocess();
    ll n,k;
    cin>>n>>k;
    ll k1 = k;
    vector<pair<ll,ll> > ans;
    for(int j:primes){
        int cont = 0;
        ll i = 1ll*j;
        while(k1%i == 0ll){
            cont++;
            k1/=i;
        }
        if( cont > 0){
            ans.push_back({1ll*i,1ll*cont});
        }
        // cout<<"DSF"<<endl;
    }
    if(k1 > 1ll){
        ans.push_back({k1*1ll,1ll});
    }
    ll ret = INFL;
    for(auto i:ans){
        ll pri = 1ll*i.first;
        ll y = 1ll*i.second;
        ll x = 0ll;
        ll temp = n;
        while(temp){
            x = x + temp/pri;
            temp/=pri;
        }
        ret = min(ret,x/y);
    }
    assert(ret <  INFL);
    cout<<ret<<endl;
    return 0;
}
