#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e6+10;
int bit[lim+1];
void update(int x, int val)
{
      for(; x <= lim; x += x&-x)
        bit[x] += val;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bit[x];
     return sum;
}
int mark[lim];
int main()
{

    int t;
    scan(t);
    int x = 1;
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        memset(bit,0,sizeof(bit));
        int n,k;
        scan2(n,k);
        ll cont = 0;
        int flag = 0;
        for(int i=0;i<n;++i)
        {
            int x;
            scan(x);
            cont+=1ll*(1ll*i- 1ll*query(x));
            update(x,1);
            if( mark[x] ==1)
                flag = 1;
            mark[x] = 1;
        }
        ll def = cont- 1l*k;
        ll  ans = def;
        if( def < 0)
        {
            def = abs(def);
            if( def%2 == 0)
                ans = 0;
            else
            {
                if( flag == 1)
                    ans = 0;
                else
                    ans = 1;
            }


        }
        printf("Case %d: %lld\n",x,ans);
        x++;
    }
    return 0;
}


