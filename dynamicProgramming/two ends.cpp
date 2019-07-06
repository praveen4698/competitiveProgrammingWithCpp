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

    int C[1001],dp[1001][1001];
    int solve(int i,int j,int p)
    {
        if( i > j)
            return 0;
        if( dp[i][j] != -1)
            return dp[i][j];
        if( p == 0)
            return dp[i][j] = max( C[i] - solve(i+1,j,1-p),C[j] - solve(i,j-1,1-p));
        else
        {
            if( C[i] >= C[j])
                return dp[i][j] = C[i] - solve(i+1,j,1-p);
            else
                return dp[i][j] = C[j] - solve(i,j-1,1-p);
        }

    }

    int main()
    {
         int n;
         scan(n);
         int c= 1;
         while( n != 0)
         {
             lp(i,0,n)
             {
                 scan(C[i]);
             }
             memset(dp,-1,sizeof(dp));
             printf("In game %d, the greedy strategy might lose by as many as %d points.\n",c,solve(0,n-1,0));
             c++;
             scan(n);
         }

        return 0;
    }

