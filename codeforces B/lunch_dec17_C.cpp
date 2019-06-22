
#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
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

const ll mod = 1e9+7;
int dp[51][51][51][3][51][3];
int main()
{
    int t;
    S(t);
    while(t--)
    {
        int P,Q,N;
        S3(P,Q,N);
        int B1,B2,S1,S2;
        S2(B1,B2);
        S2(S1,S2);
        B1 = min(B1,50);
        B2 = min(B2,50);
        S1 = min(S1,50);
        S2 = min(S2,50);
        memset(dp,0,sizeof(dp));
        for(int p=0;p<=P;++p)
        {
            for(int q=0;q<=Q;++q)
            {
                if(p == 0 && q == 0)
                    continue;
                if( p > 0)
                {
                    for(b1=1;b1<= B1;++b1)
                    {
                        for(s1=1;s1<=S1;++s1)
                        {
                            dp[p][q][b1][0][s1][1]+=dp[p-1][q][b1][0][s1-1][1];
                            dp[p][q][b1][1][s1][1]+=dp[p-1][q][b1][1][s1-1][1];
                            dp[p][q][b1][2][s1][1]+=dp[p-1][q][b1][2][s1-1][1];

                        }
                        for(s2=1;s2<=S2;++s2)
                        {
                            dp[p][q][b1][0][1][1]+=dp[p-1][q][b1-1][1][s2][2];
                            dp[p][q][b1][1][1][1]+=dp[p-1][q][b1-1][2][s2][2];
                        }
                    }
                }
                if( q > 0)
                {
                    for(b2=1;b2<=B2;++b)
                }
            }
        }

    }
    return 0;
}

