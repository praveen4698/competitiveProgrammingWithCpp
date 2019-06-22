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
const int lim = 1e5;
vector<ll> A;


int main()
{
    int t;
    scan(t);
    while(t--){
        ll n,k,x;
        ll sum = 0ll;
        cin>>n>>k>>x;
        A.clear();
        A.resize(k);
        for(int i=0;i<k;++i){
            cin>>A[i];
            sum+=A[i];
        }
        sort(all(A));
        ll prev = A[0] + x;
        ll cont = n-k;
        reverse(all(A));
        for(int i: A){
            ll temp = prev - i;
            if( temp > cont){
                 
                ll xx = cont*1ll*(prev - cont + 1 + prev)/2;
                sum+=xx;

                break;
            }

            cont-=temp;
            ll xx = (temp)*(i+ 1 + prev)/2ll;
            sum+=xx;
            prev = i-1 ;
        }
        cout<<sum<<endl;
    }
    return 0;
}
