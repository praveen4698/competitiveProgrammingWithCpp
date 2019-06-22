#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 33;
int dp[2][lim][lim][lim][lim];
string S;
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,k;
        scan2(n,k);
        cin>>S;
        memset(dp,INF,sizeof(dp));
        int cur = 0;
        dp[cur][0][0][0][0] = 0;
        for(int i=0;i<n;++i)
        {
            for(int c=0;c<lim;++c)
            {
                for(int h=0;h<lim;++h)
                {
                    for(int e=0;e<lim;++e)
                    {
                        for(int f=0;f<lim;++f)
                        {
                            if(dp[cur][c][h][e][f] < INF)
                            {
                                int val = dp[cur][c][h][e][f];
                                dp[cur][c][h][e][f] = INF;
                                dp[!cur][c][h][e][f] = min(dp[!cur][c][h][e][f],val+1);
                                if(S[i] == 'c')
                                {
                                    int nc = min(c+1,lim-1);
                                    dp[!cur][nc][h][e][f] = min(dp[!cur][nc][h][e][f],val);
                                }
                                else if(S[i] == 'h')
                                {
                                    int nh = min(lim-1,c+h);
                                    dp[!cur][c][nh][e][f] = min(dp[!cur][c][nh][e][f],val);
                                }
                                else if(S[i] == 'e')
                                {
                                    int ne = min(lim-1,h+e);
                                    dp[!cur][c][h][ne][f] = min(dp[!cur][c][h][ne][f],val);
                                }
                                else
                                {
                                    int nf = min(lim-1,e+f);
                                    dp[!cur][c][h][e][nf] = min(dp[!cur][c][h][e][nf],val);
                                }
                            }
                        }
                    }
                }
            }
            cur = !cur;
        }
        int ans = INF;
        for(int i=0;i<lim;++i)
            for(int j=0;j<lim;++j)
                for(int l=0;l<lim;++l)
                    ans = min(ans,dp[cur][i][j][l][k]);
        if( ans >= INF)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }

    return 0;
}


