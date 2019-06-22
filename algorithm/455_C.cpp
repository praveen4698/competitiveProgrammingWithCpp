#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 5010;
const ll mod = 1e9+7;
ll dp[lim],check[lim][lim];
char A[lim];
int main()
{
    memset(dp,0ll,sizeof( dp));
    memset(check,0,sizeof(check));
    int n;
    S(n);
    for(int i=1;i<=n;++i)
        cin>>A[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            if( i == j && A[i] == 's')
                check[i][j] = 1;
            if( i != j && A[i] == 'f' && A[j] == 's')
                check[i][j] = 1;
        }
    }
    dp[0] = 1;

    for(int i=1;i<=n;++i)
    {
        ll temp = 1ll;
        for(int j=1;j<=i;++j)
        {
            if( A[j] == 's')
                temp = dp[j];

            if( check[j][i] == 1)
            {
                dp[i]+=temp;
                dp[i]%=mod;

            }

        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
