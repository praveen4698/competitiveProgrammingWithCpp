#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const ll lim = 2e6 +10;
    ll A[lim],le[lim],re[lim];
    pair<ll,ll> v[lim];
    int main()
    {
        ll n,l,r;
        scanf("%lld %lld %lld",&n,&l,&r);
        lp(i,0,n)
        {
            scanf("%lld",&A[i]);
        }
        sort(A,A+n);
        lp(i,1,n)
        {
            le[i] = A[i] - A[i-1] + 1;
            re[i] = A[i] + A[i-1] - 1;
          //  printf("%lld\n",re[i]);
        }
        v[0].F = le[1];
        v[0].S = re[1];
        int counti = 1;
      //  lp(i,1,n)
      //  {
           // printf("%lld %lld\n",le[i],re[i]);
      //  }
       // printf("yo\n");
        lp(i,2,n)
        {
            int value = -1;
            lp(j,0,counti)
            {
              //  printf("ss--%lld\n",v[j].S);
                if(v[j].S >= le[i])
                {
                    value = j;
                    break;
                }

            }
            if( value == -1)
            {
                v[counti].F = le[i];
                v[counti].S = re[i];
             //   printf("rere %lld\n",re[i]);
                counti++;
            }
            else
            {
                v[value].F = min(v[value].F,le[i]);
                v[value].S = max(v[value].S,re[i]);
               // printf("rere %lld %lld \n",re[i],v[value].S);
                counti = value + 1;
            }

        }
        ll ans = 0;
        lp(i,0,counti)
        {
            if(v[i].F > r)
                break;
            if(v[i].S < l)
                continue;
            if(v[i].F < l)
                v[i].F = l;
            if( v[i].S > r)
                v[i].S = r;
           // printf("%lld %lld\n",v[i].F,v[i].S);
            ans = ans + v[i].S - v[i].F + 1;


        }
        printf("%lld\n",ans);
        return 0;
    }
