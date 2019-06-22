#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef complex<double> base;
const double PI = 4*atan(1);
void fft (vector<base> &a, bool invert)
{
	int n = (int)a.size();
	if (n <= 1)
        return;

	vector<base> a0(n/2),a1(n/2);
	for(int i=0,j=0;i<n;i+=2, ++j)
    {
		a0[j] = a[i];
		a1[j] = a[i+1];
    }
	fft(a0,invert);
	fft(a1,invert);

	double ang = 2*PI/n*(invert?-1:1);
	base w(1),wn(cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i)
    {
		a[i] = a0[i] + w*a1[i];
		a[i+n/2] = a0[i]-w*a1[i];
		if (invert)
			a[i]/=2,a[i+n/2]/=2;
		w *= wn;
	}
}
//iterative
/*
int rev (int num, int lg_n) {
	int res = 0;
	for (int i=0; i<lg_n; ++i)
		if (num & (1<<i))
			res |= 1<<(lg_n-1-i);
	return res;
}

/*void fft (vector<base> & a, bool invert = false) {
	int n = (int) a.size();
	int lg_n = 0;
	while ((1 << lg_n) < n)  ++lg_n;

	for (int i=0; i<n; ++i)
		if (i < rev(i,lg_n))
			swap (a[i], a[rev(i,lg_n)]);

	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}*/
void multiply (const vector<ll> &a,const vector<ll> &b,vector<ll> &res)
{
	vector<base> fa(a.begin(),a.end()), fb(b.begin(),b.end());
	size_t n = 1;
	while(n<max(a.size(),b.size()))
        n <<= 1;
	n <<= 1;
	fa.resize(n);
    fb.resize(n);

	fft(fa,false),
    fft(fb,false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft(fa,true);

	res.resize(n);
	for (size_t i=0; i<n; ++i)
		res[i] = ll (fa[i].real() + 0.5);
}
vector<long long > A,B,ans;
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n;
        scan(n);
        A.clear();
        B.clear();
        A.resize(n+1);
        B.resize(n+1);
        for(int i=0;i<n+1;++i)
            cin>>A[i];
        for(int i=0;i<n+1;++i)
            cin>>B[i];
        ans.clear();
        multiply(A,B,ans);
        for(int i = 0;i<2*n+1;++i)
            cout<<ans[i]<<" ";
        cout<<endl;

    }

    return 0;
}


