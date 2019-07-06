#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
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
    const int lim = 1e5 + 10;
    const ll mod = 1e9+7;
    ll A[lim],sumi[lim];
    int main()
    {
        int t,k;
        scan2(t,k);
        lp(i,0,lim)
        {
            if( i < k)
                A[i] = 1;
            else
                A[i] = A[i-1] + A[i-k];
            A[i] = A[i]%mod;
        }
        sumi[0] = A[0];
        lp(i,1,lim)
        {
            sumi[i] = sumi[i-1]+ A[i];
            sumi[i] = sumi[i]%mod;
        }
        lp(i,0,t)
        {
            ll a,b;
            cin>>a>>b;
            ll res = sumi[b] - sumi[a-1];
            if( res < 0)
             {
                 res = res + mod;

             }
             cout<<res%mod;
            printf("\n");
        }

        return 0;
    }
