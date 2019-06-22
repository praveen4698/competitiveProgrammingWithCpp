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
const ll mod = 1e9 + 7;
    bool ok(string s , int n)
{
set < char > mset;
for(int i = 0; i < n; ++i)    {
        mset.insert(s[i]);
}
bool rekt = 1;
for(int i = 0; i < n; ++i)    {
         rekt &= s[i] == s[n - i - 1];
}
if(mset.size() >= ( (n >> 1) + (n & 1) )   && rekt)    {
      return 1;
}
return 0;
}

    int main()
    {
        int t;
        scan(t);
       // printf("%d",ok("bbb",3));
        while(t--)
        {
           ll n;
           scanf("%lld",&n);
           if( n > 52)
                printf("0\n");
           else
           {
               ll counti = 1;
               ll r = 26;
               lp(i,0,n/2+n%2)
               {
                   counti = counti*r;
                   counti = counti%mod;
                   r--;
               }
               printf("%lld\n",counti);
           }
        }
        return 0;
    }
