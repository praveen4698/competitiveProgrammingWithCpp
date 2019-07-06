#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, p[ 1000100 ], fw[ 1000100 ];
long long pref[ 1000100 ], ans = 0;

bool cmp( int a, int b )
{
    return make_pair( pref[a], a ) < make_pair( pref[b], b );
}

void modify( int pos )
{
    while ( pos < 1000100 )
    {
        fw[pos] += 1;
        pos = pos + pos - ( pos & (pos - 1) );
    }
}

int fsum( int pos )
{
    int res = 0;
    while ( pos )
    {
        res += fw[pos];
        pos = pos & (pos - 1);
    }
    return res;
}

int main (int argc, const char * argv[])
{
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i++ )
    {
        int a; scanf("%d", &a);
        a -= k;
        pref[i] = pref[i - 1] + a;
        p[i] = i;
    }
    for(int i = 0;i <= n;++i)
        printf("%d %lld\n",p[i],pref[i]);
    sort( p, p + n + 1, cmp );
    for(int i = 0;i <= n;++i)
        printf("%d\n",p[i]);
    for ( int i = 0; i <= n; i++ )
    {
        ans += fsum( p[i] + 1 );
        modify( p[i] + 1 );
    }
    printf("%lld\n", ans);
    return 0;
}
