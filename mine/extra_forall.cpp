
// order statistics tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
// function order_of_key(i) gives A[i];
// insert
// ersase by value not by index
// find_by_order
// for splay tree - use splay_tree_tag
                string temp;
                getline( cin , temp );
                stringstream ss( temp );
                int x , y;
                int j = 0;
                while ( ss >> x && ss >> y )
                {

                    A[ x ][ y ] = i ;
                    if( j == 0)
                    {
                        Q[i].push(mp(x,y));
                        j++;
                    }
                }

        struct compare{
        bool operator()(const pair<int,int> l,const pair<int,int> r)
			{
				return l.S > r.S;
			}


		};
clock_t start = clock();
  //  cout<<"saF"<<endl;
    clock_t end = clock();
    cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
struct comp
{
    bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
    {
        return lhs.second<rhs.second;
    }
};//increasing
        // but reverse in priority_queue;
inline int readint()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f = -1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

struct Matrix
{
    ll a,b,c,d;
    Matrix(ll a1,ll b1,ll c1,ll d1)
    {
        a = a1;
        b = b1;
        c = c1;
        d = d1;
    }
};
Matrix MUL(Matrix A,Matrix B)
{
    ll a1 = (A.a*B.a + A.b*B.c)%mod;
    ll b1 = (A.a*B.b + A.b*B.d)%mod;
    ll c1 = (A.c*B.a + A.d*B.c)%mod;
    ll d1 = (A.c*B.b + A.d*B.d)%mod;
    return  Matrix(a1,b1,c1,d1);
}
// to enlarge stack;
#include<sys/resource.h>
void enlargeStack ()
{
    struct rlimit lim;
    getrlimit(RLIMIT_STACK, &lim);
    lim.rlim_cur = lim.rlim_max;
    setrlimit(RLIMIT_STACK, &lim);
}

  ll hi = 1e18;
        ll ans = -1;
        ll lo = 1;
        while(hi >= lo){
            ll mid = (hi+lo+1)/2;
            // cout<<lo<<" "<<hi<<" "<<mid<<endl;
            if( check(mid) == true){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid +1;
            }
        }
//primes;
// A[i] will give the primefactor of i
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
// phi function

int phi(int n)
{   int ret=n; int i = 2;
    if(n%i==0){
        ret-=ret/i;
        while(n%i==0)
            n/=i;
    }
    for(i=3; i*i<=n; i++)
        if(n%i==0)
        {
            ret-=ret/i;
            while(n%i==0)
                n/=i;
        }
    if(n>1)
        ret-=ret/n;
    return ret;
}

// for mod
const int mod = 1e9 + 7;
const int lim = 1e6;
int pil[lim],phi[lim];
int fact[lim],int invfact[lim];
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
vector<int> factorize(int n){
	vector<int> vec;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			while(n % i == 0) n /= i;
			vec.push_back(i);
		}
	}
	if(n != 1) vec.push_back(n);
	return vec;
}
void factorials(){
    fact[0]=1;
    for(int i=1;i<lim;i++)
        fact[i] = mul(fact[i-1],i);
    invfact[lim-1] = inv(fact[lim-1]);
    for(int i=lim-2;i>=0;i--)
        invfact[i] = mul(invfact[i+1],i+1);
}
int ncr(int n,int r){
    if(n<r||n<0)
    return 0;
    int ans = mul(fact[n],invfact[r]);
    ans = mul(ans,invfact[n-r]);
    return ans;
}
void compute_phi(){
    for(int i = 1; i < lim; i++)
        phi[i] = i;

    for(int i = 1; i < lim; i++)
        for (int j = i + i; j < lim; j += i)
            phi[j] -= phi[i];

}
void compute_pillai(){
    for(int i = 1; i < lim; i++)
        for(int j = i; j < lim; j += i)
            pil[j] = add(pil[j],i*phi[j/i]);
}

// fib in log n;
unordered_map<int,int> fibo_cache;
unordered_map<int,int>::const_iterator fibo_cache_it;
int Fibo(int n)
{
    if (n <= 0) return 0;
    if (n <= 2) return 1;
    fibo_cache_it = fibo_cache.find(n);
    if (fibo_cache_it != fibo_cache.end()) return fibo_cache_it->second;
    int f, right, left;
    right = (n >> 1); left = n - right;
    f = ((long long)Fibo(left)*(long long)Fibo(right+1)+(long long)Fibo(left-1)*(long long)Fibo(right)) % MOD;
    return fibo_cache[n] = f;
}
//compi
/*
ID: praveen95
TASK: test
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}
// matrix

typedef vector<vector<ll> >  matrix; //define matrix
matrix I;   //identity matrix
#define mod 1000000007
// multiply two matrices
matrix multiply(matrix A, matrix B)
{
    int n=(int)A.size();
    matrix C(n, vector<ll>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;++k)
            {
                C[i][j] = C[i][j] + (A[i][k] * B[k][j])%MOD;
                if(C[i][j]>=MOD)
                    C[i][j]-=MOD;
            }
    return C;
}

//find N'th power of matrix T
matrix mpow(matrix T, LL N)
{
    if(N==0)return I;
    if(N==1)return T;
    matrix ret =mpow(T,N/2);
    matrix ret1=multiply(ret,ret);
    if(N%2==0)return ret1;
    else return multiply(ret1,T);
}
