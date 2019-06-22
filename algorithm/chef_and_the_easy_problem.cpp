#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
const int logn = 31;
int sum[lim][logn];
int A[lim];

int main()
{
    int n,q;
    memset(sum,0,sizeof(sum));
    scan2(n,q);
    for(int i=1;i<=n;++i)
    {
        scan(A[i]);
        for(int j=0;j<logn;++j)
        {
            sum[i][j]+=sum[i-1][j];
            if( (1<<j)&A[i] )
                sum[i][j]++;
        }
    }
 //   for(int i=0;i<logn;++i)
 //       printf("")
    while(q--)
    {
        int l,r;
        scan2(l,r);
        ll x = 0ll;
        int half = (r-l+1)/2;
        bool even = ((r-l+1)%2==0);
        for(int i=0;i<logn;++i)
        {
            int a = sum[r][i] - sum[l-1][i];
           // cout<<i<<" "<<a<<endl;
            if( (a == half && even ) || a > half)
                continue;
            else
                x |= (1<<i);
           // cout<<x<<endl;
        }
        print(x);
    }
    return 0;
}


