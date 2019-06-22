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
const int logn= 32;
int A[lim],cont[logn +1];

int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        memset(cont,0,sizeof(cont));
        for(int i=0;i<n;++i){
            scan(A[i]);
            for(int j=0;j<logn;++j){
                if( A[i]&(1<<j))
                    cont[j]++;
            }
        }
        int x = 0;
        for(int i=0;i<logn+1;++i){
            // cout<<cont[i]<<endl;
            if( cont[i] > n/2){
                x+=(1<<i);
            }
        }
        // cout<<x<<endl;
        ll ans = 0;
        for(int i=0;i<n;++i){
            ans = ans + 1ll*(A[i]^x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
