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
const int lim = 2e6+10;
int A[lim],col[lim],row[lim];

int main()
{
    memset(A,0,sizeof(A));
    memset(col,0,sizeof(col));
    memset(row,0,sizeof(row));
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        int a,b;
        scan2(a,b);
        if( b >= a)
        {
            col[b-a]++;
        }
        else
        {
            row[a-b]++;
        }
        A[b+a]++;
    }
    ll ans = 0ll;
    for(int i=0;i<2*n+10;++i)
    {
        if( A[i] > 1 )
            ans = ans + (A[i])*1ll*(A[i]-1)/2;
        if( col[i] > 1)
            ans = ans + (col[i])*1ll*(col[i]-1)/2;
        if( row[i] > 1)
            ans = ans + (row[i])*1ll*(row[i]-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}


