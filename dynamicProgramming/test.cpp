
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <cstdlib>

#define mp make_pair
#define pb push_back

const long long inf = 1e18;
const int maxn = 100100;
const int maxd = 50050;
const int maxm = 100100;
const int maxlogd = 18;

using namespace std;

struct node
{
	int sum, lson, rson;
	node()
	{
		sum = 0;
		lson = rson = -1;
	}
};

node Tree[ maxn * maxlogd ];
int n, m, Root[ maxn ], nnode = 1;
pair< int, int > P[ maxn ];

int make_version( int v, int l, int r, int pos, int pls )
{
	int newid = nnode++;
	if ( v != -1 ) Tree[ newid ] = Tree[v];
	Tree[ newid ].sum += pls;
	if ( l == r ) return newid;
	int x = (l + r) / 2;
	if ( pos <= x )
		Tree[ newid ].lson = make_version( Tree[ newid ].lson, l, x, pos, pls );
	else
		Tree[ newid ].rson = make_version( Tree[ newid ].rson, x + 1, r, pos, pls );
	return newid;
}

int fsum( int v, int l, int r, int ll, int rr )
{
	if ( v == -1 ) return 0;
	if ( l == ll && rr == r ) return Tree[v].sum;
	int xx = (ll + rr) / 2, res = 0;
	if ( l <= xx )
		res += fsum( Tree[v].lson, l, min( r, xx ), ll, xx );
	if ( xx + 1 <= r )
		res += fsum( Tree[v].rson, max( xx + 1, l ), r, xx + 1, rr );
	return res;
}

int rect( int l, int r, int x )
{
	int ll = 1, rr = n, res = 0;
	while ( ll <= rr )
	{
		int xx = (ll + rr) / 2;
		if ( P[xx].first <= x )
		{
			res = max( res, xx );
			ll = xx + 1;
		} else rr = xx - 1;
	}
	return fsum( Root[res], l, r, 1, n );
}

int fun( int l, int r )
{
	int k = 0;
	while ( true )
	{
		int cur = rect( l, r, k + 1 );
		if ( cur > k )
		{
			k = cur;
			continue;
		}
		return k + 1;
	}
}

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
    	scanf("%d", &P[i].first);
    	P[i].second = i;
    }
    sort( P + 1, P + n + 1 );
    Root[0] = 0;
    for ( int i = 1; i <= n; i++ )
    	Root[i] = make_version( Root[i - 1], 1, n, P[i].second, P[i].first );
   	scanf("%d", &m);
   	for ( int q = 1; q <= m; q++ )
   	{
   		int l, r; scanf("%d%d", &l, &r);
   		printf("%d\n", fun( l, r ));
   	}
    return 0;
}
