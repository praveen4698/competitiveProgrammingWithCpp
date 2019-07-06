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
const int lim = (1<<22)-1;
int dp[lim+10],A[lim];

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        scan(A[i]);
        dp[A[i]] = i;
    }
    for(int i=0;i<=lim;++i)
    {
        if( dp[i] == -1)
        {
            for(int j=0;j<22;++j)
            {
                if( (i&(1<<j)) !=  0)
                {
                    int mask  = i^(1<<j);
                    if( dp[mask] != -1)
                    {
                       // if( i< 10)
                       //     cout<<i<<" "<<mask<<endl;
                        dp[i] = dp[mask];
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        int ans = dp[lim-A[i]];
        //cout<<ans<<" ";
        if( ans != -1)
            ans = A[ans];
        printf("%d ",ans);
    }
    printf("\n");
    return 0;
}


