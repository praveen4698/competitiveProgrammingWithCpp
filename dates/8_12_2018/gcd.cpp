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

vector<int> A,B;
int main()
{
    int n;
    scan(n);
    ll gcd = 0ll;
    A.resize(n);
    B.resize(n);
    for(int i=0;i<n;++i){
        scan2(A[i],B[i]);
        gcd = __gcd(gcd,1ll*A[i]*B[i]);
    }
    if( gcd == 1) {
        print(-1);
        return 0;
    }
    for(int i=0;i<n;++i){
        ll temp = __gcd(gcd,1ll*A[i]);
        if( temp > 1)
            gcd = temp;
        temp = __gcd(gcd,1ll*B[i]);
        if( temp > 1)
            gcd = temp;
    }
    print(gcd);
    return 0;
}
