#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
#define REP(i, a, b) for (auto i = (a); i < (b); i++)
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int lim = 1e4;
int pil[lim],phi[lim];
int fact[lim],invfact[lim];
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
void factorials(){
    fact[0]=1;
    for(int i=1;i<lim;i++)
        fact[i] = mul(fact[i-1],i);
    invfact[lim-1] = inv(fact[lim-1]);
    for(int i=lim-2;i>=0;i--)
        invfact[i] = mul(invfact[i+1],i+1);
}
int ncr2(int n,int r){
    if(n<r||n<0 || r<0)
    return 0;
    if (!n) return !r;
    int ans = mul(fact[n],invfact[r]);
    ans = mul(ans,invfact[n-r]);
    return ans;
}
const ll g_mod = 1e9 + 7;
const int g_max_n = 1000;

inline ll mmi(int n) { // returns n^(-1) mod g_mod
	static int last = 1;
	static vector<ll> mmi_table(g_max_n + 1);
	mmi_table[1] = 1;
	REP (i, last + 1, n + 1)
		mmi_table[i] = (g_mod - (g_mod/i) * mmi_table[g_mod % i] % g_mod) % g_mod;
	last = max(last, n);
	return mmi_table[n];
}

inline ll factorial(int n, int inv = 0) {
	// inv = 0 returns n! modulo g_mod, inv = 1 return (n!)^(-1) modulo g_mod
	static int last = 0;
	static vector<array<ll, 2>> factorial_table(g_max_n + 1);
	factorial_table[0][0] = factorial_table[0][1] = 1;
	REP (i, last + 1, n + 1) {
		factorial_table[i][0] = (i*factorial_table[i - 1][0]) % g_mod;
		factorial_table[i][1] = (mmi(i)*factorial_table[i - 1][1]) % g_mod;
	}
	last = max(last, n);
	return factorial_table[n][inv];
}

inline int ncr(int n, int k) { // returns C(n, k) mod g_mod
	if (k > n || k < 0) return 0;
	if (!n) return !k;
	return ((factorial(n, 0)*(factorial(k, 1)*factorial(n - k, 1) % g_mod)) % g_mod);
}
int main() {
    
	int _t; cin >> _t;
    factorials();
    // for(int i=0;i<lim;++i){
    //     if( fact[i] != factorial(i))
    //         cout<<i<<endl;
    //     if( invfact[i] != factorial(i,1))
    //         cout<<"inv"<<i<<endl;
    // }
    // cout<<"Sdf"<<endl;
	while(_t--) {
        
		int n; cin >> n;
		map<int, int> element;
		REP (i, 0, n) {
			int x; cin >> x;
			element[x]++;
		}
		int  result = 0;
		int prev = 0; // keeps track of the numbers preceeding the current one
		for (const auto &x : element) {
			int e = x.second;
			int tmp = ncr2(n - e, prev);
            // cout<<ncr(n-e,prev)<<" "<<ncr2(n-e,prev)<<endl;
			// result = (result + ((e*1ll*tmp) % mod)) % mod;
            result = add(result,mul(e,tmp));
            // cout<<result<<"asf"<<endl;
			REP (i, 2, e + 1) {
				// tmp = (tmp + 1ll*ncr(n - e, prev - i + 1) + 1ll*ncr(n - e, prev + i - 1)) % mod;
                tmp = add(tmp,add(ncr2(n - e, prev - i + 1), ncr2(n - e, prev + i - 1)));
                // cout<<ncr(n - e, prev - i + 1)<<" "<<ncr2(n - e, prev - i + 1)<<endl;
                // cout<<ncr(n - e, prev + i + 1)<<" "<<ncr2(n - e, prev + i + 1)<<endl;
				// result = (result + ((ncr(e, i)*1ll*tmp) % mod)) % mod;
                result = add(result, mul(ncr2(e,i),tmp));
                // cout<<ncr(e,i)<<" "<<ncr2(e,i)<<endl;
			}
			prev += e;
		}
		cout << result << "\n";
	}

	return 0;
}
