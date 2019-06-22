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

    ll addon( ll start,ll endi,ll nos)
    {
        return ((nos*(start+endi))/2);
    }
    int main()
    {
        int t;
        scan(t);
        int i = 1;
        while(t--)
        {
            long long int n;
            scanf("%lld",&n);
            ll counti = 0;
            if( n%7 == 0 || n%13 == 0)
                n = n-1;
            counti = counti + addon(7,n-n%7,n/7);
            counti = counti + addon(13,n-n%13,n/13);
            counti = counti - addon(91,n-n%91,n/91);
            printf("Case %d: %lld\n",i,counti);
            i++;

        }
        return 0;
    }
