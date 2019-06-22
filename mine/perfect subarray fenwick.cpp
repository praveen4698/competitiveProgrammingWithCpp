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
    const int lim = 1e6 + 10;
    int n,k,fn[lim],p[lim];
    ll sum[lim];
    bool comp(int a,int b)
    {
        return make_pair(sum[a],a) < make_pair(sum[b],b);
    }
    void modify( int pos )
    {
        while ( pos < 1000100 )
        {
            fn[pos] += 1;
            pos+=(pos&(-pos));
            //pos = pos + pos - ( pos & (pos - 1) );
        }
    }
    int query( int pos )
    {
        int res = 0;
        while ( pos )
        {
            res += fn[pos];
            pos = pos & (pos - 1);
        }
        return res;
    }
    int main()
    {
        scan2(n,k);
        int a;
        lp(i,1,n+1)
        {
            scan(a);
            a= a - k;
            sum[i] = sum[i-1] +a;
            p[i] = i;
        }
      //  for(int i = 0;i <= n;++i)
       // printf("%d %lld\n",p[i],sum[i]);
        sort(p,p+n+1,comp);
        ll ans = 0;
       // for(int i = 0;i <= n;++i)
       // printf("%d\n",p[i]);
        lp(i,0,n+1)
        {
            ans+=(ll)query(p[i] + 1);
            modify(p[i]+1);
        }
        printf("%lld\n",ans);
        return 0;
    }
