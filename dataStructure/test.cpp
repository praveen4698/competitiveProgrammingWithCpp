#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
#include <cassert>
#include <functional>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define PI acos(-1)
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long

using namespace std;

#define oo 1000000000
#define MAXN 20

int f[(1 << MAXN) + 10];
bool c[MAXN][MAXN];
int deg[MAXN];
int n, m;

int nextInt(int l, int r) {

	int x;
	assert(scanf("%d", &x) == 1);
	assert(l <= x && x <= r);

	return x;
}

int getBit(int s, int i) {
	return (s >> i) & 1;
}

int clearBit(int s, int i) {
	return s & (~(1 << i));
}

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	n = nextInt(1, 20);
	m = nextInt(0, n * (n - 1) / 2);

	for (int i = 1; i <= m; i++) {
		int u = nextInt(1, n);
		int v = nextInt(1, n);

		u--;
		v--;

		assert(u != v);
		assert(!c[u][v]);
		c[u][v] = c[v][u] = true;

		deg[u]++;
		deg[v]++;
	}


	int bit[40];
	int len;

	for (int s = 1; s < (1<<n); s++) {
		f[s] = oo;

		len = 0;
		for (int i =0; i < n; i++)
			if (getBit(s, i))
				bit[++len] = i;


		for (int i = 1; i <= len; i++) {
			int pos = bit[i];

			int cnt = 0;
			for (int j = 1; j <= len; j++)
				cnt += c[bit[j]][pos];

			int t = clearBit(s, pos);

			f[s] = min (f[s], f[t] + len * (2*cnt - deg[pos]));
			cout<<s<<" "<<f[s];
			cout<<endl;
		}
	}

	cout <<f[(1<<n) - 1] << endl;
	return 0;
}
