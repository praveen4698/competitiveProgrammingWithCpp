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
// const ll MOD = 1e9+7;
// const ll mod = 998244353;
const int mod = 1e9 + 7;
const int lim = 1e6;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1%mod;
	while(b){
		if(b&1) x = mul(x, a);
		a = mul(a,a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
int ncr(int n,int r){
    if(n<r||n<0)
    return 0;
    int ans = 1;
    for(int i=0;i<r;++i){
        ans = mul(ans,n-i);
    }
    for(int i=1;i<=r;++i)
        ans = mul(ans,inv(i));
    return ans;
}
int main()
{
    int t;
    scan(t);
    while(t--){
        int n,k;
        scan2(n,k);
        if( k == 0){
            print(0);
            continue;
        }
        int ans = 0;
        for(int i=1;i<=k;++i){
            int temp = mul(ncr(k-1,i-1),mul(powr(2,i),ncr(n-k+1,i)));
            ans = add(temp,ans);
        }
        print(ans);
    }
    return 0;
}
