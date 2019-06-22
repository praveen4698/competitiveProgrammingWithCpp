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
const int mod = 1e9 + 7;
const int lim = 1e6;
int pil[lim],phi[lim];
int fact[lim], invfact[lim];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b,ll mod1 = mod)
{
	int x = 1%mod1;
	while(b)
    {
		if(b&1) x = (((__int128)x)*a)%mod1;
		a = (((__int128)a)*a)%mod1;
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
vector<int> factorize(int n)
{
	vector<int> vec;
	for(int i = 2; i * i <= n; i++)
    {
		if(n % i == 0)
		{
			while(n % i == 0) n /= i;
			vec.push_back(i);
		}
	}
	if(n != 1) vec.push_back(n);
	return vec;
}
void factorials()
{
    fact[0]=1;
    for(int i=1;i<lim;i++)
        fact[i] = mul(fact[i-1],i);
    invfact[lim-1] = inv(fact[lim-1]);
    for(int i=lim-2;i>=0;i--)
        invfact[i] = mul(invfact[i+1],i+1);
}
int ncr(int n,int r)
{
    if(n<r||n<0)
    return 0;
    int ans = mul(fact[n],invfact[r]);
    ans = mul(ans,invfact[n-r]);
    return ans;
}
void compute_phi()
{
    for(int i = 1; i < lim; i++)
        phi[i] = i;

    for(int i = 1; i < lim; i++)
        for (int j = i + i; j < lim; j += i)
            phi[j] -= phi[i];

}
void compute_pillai()
{
    for(int i = 1; i < lim; i++)
        for(int j = i; j < lim; j += i)
            pil[j] = add(pil[j],i*phi[j/i]);
}

int main()
{
    int t;
    scan(t);
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        if( a == b){
            cout<<(powr(a,n,mod)+powr(b,n,mod))%mod;
        }
        else{
            cout<<__gcd((powr(a,n,abs(a-b))+powr(b,n,abs(a-b)))%abs(a-b),abs(a-b))<<endl;
        }
    }
    return 0;
}
