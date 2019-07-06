#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    ll power(ll n,ll p,ll MOD)
    {
        if( p == 0)
            return 1;
        ll temp = power(n,p/2,MOD);
        temp = (temp*temp)%MOD;
        if( p%2 == 0)
            return  temp;
        else
            return (n*temp)%MOD;
    }
    ll firstk(ll n,ll k)
    {
       long double m = n*log10l(n);
        long double p = powl(10,m-(int)m);
        long long ans = (long long)(p*pow(10,k-1));
        return ans;
    }

    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            ll n,k;
            scanf("%lld %lld",&n,&k);
            printf("%lld ",firstk(n,k));
        ll least = power(n,n,pow(10,k));
        if(k == 1) printf("%01lld\n", least);
		if(k == 2) printf("%02lld\n", least);
		if(k == 3) printf("%03lld\n", least);
		if(k == 4) printf("%04lld\n", least);
		if(k == 5) printf("%05lld\n", least);
		if(k == 6) printf("%06lld\n", least);
		if(k == 7) printf("%07lld\n", least);
		if(k == 8) printf("%08lld\n", least);
		if(k == 9) printf("%09lld\n", least);
	}

        return 0;
    }
