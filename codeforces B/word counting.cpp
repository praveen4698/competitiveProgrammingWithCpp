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
typedef map<char,long long > mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9+7;
    ll power( ll x ,ll y)
    {
        if( y == 0)
            return 1;
        ll temp = power(x,y/2)%mod;
        temp = (temp*temp)%mod;
        if( y%2 == 0)
            return temp;
        else
            return (temp*x)%mod;

    }

    int main()
    {
        mci M;
        char A[501];
        int t;
        scan(t);
        while(t--)
        {
            scanf("%s",A);
            ll n = strlen(A);
            ll counti = 1;
            M.clear();
            for(ll i = 1;i <= n;++i)
            {
                counti = counti*i;
                counti = counti%mod;
            }
            lp(i,0,n)
            {
                M[A[i]]++;
            }
            ll temp = 1;
            mci::iterator it;
            for(it = M.begin(); it != M.end();++it)
            {
              //  cout<<it->first<<" "<<it->second;
             //   printf("\n");
                if( it->second == 0 )
                    continue;
                else
                {
                    lp(i,1,it->second+1)
                    {
                        temp = temp*i;
                        temp = temp%mod;
                    }
                }
            }
          //  printf("%lld\n",temp);
            ll rest = power(temp,mod-2)%mod;
            rest = (counti*rest)%mod;
            printf("%lld\n",rest);


        }
        return 0;
    }

