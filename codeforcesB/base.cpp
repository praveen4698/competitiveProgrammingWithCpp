
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
    vector<ll> A;
    const ll lim = 1000000000001ll;
    void pre_compute()
    {
        lp(i,2,10001)
        {
            ll j = 1ll*i*i*i;
            while( j < lim)
            {
                A.pb(j);
                j = j*i;
            }
        }
        sort(A.begin(),A.end());
    }

    int main()
    {
        int t;
        scan(t);
        pre_compute();
        while(t--)
        {
            ll n;
            scanf("%lld",&n);
            if( n == 1)
                printf("INFINITY\n");
            else
            {
                ll ans = (n+1)/2;

                ans+=((int )sqrt(n) - (int )sqrt(n/2));
                ans+=upper_bound(A.begin(),A.end(),n) - upper_bound(A.begin(),A.end(),n / 2);

                printf("%lld\n",ans);
            }
        }
        return 0;
    }
