#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int lim = 1e6;
int pil[lim],phi[lim];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b)
{
	int x = 1 % mod;
	while(b)
    {
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
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
void compute_phi()
{
    for(int i = 1; i < lim; i++)
        phi[i] = i;
    for(int i = 2; i < lim; i++)
        if (phi[i] == i)
            for(int j = i; j < lim; j += i)
                phi[j] = sub(phi[j],phi[j]/i);

}

void compute_pillai()
{
    for(int i = 1; i < lim; i++)
        for(int j = i; j < lim; j += i)
            pil[j] = add(pil[j],i*phi[j/i]);

}
int bit[lim+1];
void update(int x, int val)
{
      for(; x <= lim; x += x&-x)
        bit[x] = add(bit[x],val);
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum = add(sum,bit[x]);
     return sum;
}
int A[lim];
int main()
{
    memset(bit,0,sizeof(bit));
    compute_phi();
    compute_pillai();
    int n,q;
    S(n);
    for(int i=1;i<=n;++i)
    {
        S(A[i]);
        update(i,pil[A[i]]);
    }
    S(q);
    while(q--)
    {
        char a;
        int b,c;
        cin>>a;
        S2(b,c);
        if(a == 'U')
        {
            update(b,sub(pil[c],pil[A[b]]));
            A[b] = c;
        }
        else
        {
            printf("%d\n",sub(query(c),query(b-1)));
        }
    }
    return 0;
}
