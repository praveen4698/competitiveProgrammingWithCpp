#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define scan(a) scanf("%d",&a)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int dp[5001][5001];
    char s[5001];
    int cal(int i ,int j)
    {
        if( i > j)
            return INF;
        if( i == j)
            return 0;
        if( i == j-1)
            return s[i] == s[j]?0:1;
        if( dp[i][j] != -1)
            return dp[i][j];
        if( s[i] == s[j])
            return dp[i][j] = cal( i+1,j-1);
        else
            return dp[i][j] = min( cal(i+1,j),cal(i,j-1)) + 1;


    }

    int main()
    {
        //ios_base::sync_with_stdio(false);
       // cin.tie(NULL);
        int n;


            scan(n);
            scanf("%s",s);
            //int n = strlen(s);
            lp(i,0,n)
            {
                lp(j,0,n)
                {
                    dp[i][j] = -1;
                }
            }
            int re = cal(0,n-1);
            printf("%d\n",re);

        return 0;
    }

