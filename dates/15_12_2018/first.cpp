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


int main()
{
    ll L[10],R[10];
    ll A[10];
    int t;
    scan(t);
    while(t--){
        ll k;
        cin>>k;
        for(int i=1;i<=7;++i)
            cin>>A[i];
        L[0] = 0ll;
        for(int i=1;i<=7;++i){
            L[i] = L[i-1]+A[i];
        }
        int n = L[7];
        R[8] = 0;
        for(int i=7;i>=1;--i){
            R[i] = A[i] + R[i+1];
        }
        ll ans = INFL;
        for(int i=1;i<=7;++i ){
            for(int j=1;j<=7;++j){
                ll temp = 8-i+j;
                ll x = R[i] + L[j];
                x = k-x;
                if( x < 0)
                    x = 0ll;
                temp  = temp + 7ll*(x/n);
                if( x%n != 0)
                    temp+=7;
                ans = min(temp,ans);

            } 
        }
        for(int i=1;i<=7;++i){
            for(int j=i;j<=7;++j){
                if( L[j]-L[i-1] >= k){
                    ans = min(1ll*j- 1ll*i + 1ll,ans);
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
