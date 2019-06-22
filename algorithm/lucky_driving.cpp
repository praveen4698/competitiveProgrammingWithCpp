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
const int mod = 1e9+7;
ll dp[50][5],dp1[50][5];
int main()
{
    int t;
    S(t);
    string A;
    while(t--)
    {
        cin>>A;
        int n = A.length();
        memset(dp,0ll,sizeof(dp));
        dp[0][0] = 1ll;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<37;++j)
            {
                for(int k=0;k<5;++k)
                {
                    dp1[j][k] = dp[j][k];
                }
            }
            for(int j=0;j<=27;j++)
            {
                int x = (int)A[i]-'0';

                for(int k=1;k<=4;++k)
                {
                    dp[x+j][k]+=dp1[j][k-1];
                    if( dp[x+j][k] >= mod)
                        dp[x+j][k]-=mod;
                    //if( i == 3 && j == 9)
                     //   cout<<j<<" "<<k<<" "<<dp1[j][k-1]<<" "<<x+j<<" "<<dp[x+j][k]<<endl;
                }

            }
        }
        ll ans = 0ll;
        for(int i=1;i<40;++i)
        {
            for(int j=1;j<5;++j)
            {

                if(i%9 == 0)
                {
                  //  cout<<" "<<i<<" "<<j<<" "<<dp[i][j];
                    ans+=dp[i][j];
                    ans%=mod;
                  //  cout<<endl;
                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
