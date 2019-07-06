#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    long long int dp[201][201];
    char A[201];
    bool used;
    char opp(char a)
    {
        if( a == '(')
            return ')';
        else if ( a == '{')
            return '}';
        else if ( a == '[')
            return ']';
        return '0';
    }
    void bracket(long long int lo ,long long int hi,long long int  MOD)
    {
        if( hi <= lo)
        {
            dp[lo][hi] = 1;
            return ;
        }
        dp[lo][hi] = 0;
        for(long long int i = lo+1;i<=hi;i = i+2)
        {
            if( dp[lo+1][i-1] == -1)
                bracket(lo+1,i-1,MOD);
            if( dp[i+1][hi] == -1)
                bracket(i+1,hi,MOD);
            long long int temp = dp[lo+1][i-1]*dp[i+1][hi];
            if( A[i] == opp(A[lo]))
            {
                dp[lo][hi]+=temp;
                if( dp[lo][hi] >= MOD)
                 {
                     dp[lo][hi] = dp[lo][hi]%MOD;
                     used = true;
                 }
            }
            if( A[i] == '?' && A[lo] == '?')
            {
                dp[lo][hi]+=(3*temp);
                 if( dp[lo][hi] >= MOD)
                 {
                     dp[lo][hi] = dp[lo][hi]%MOD;
                     used = true;
                 }
            }
            else if ( (A[i] == '?') && (A[lo] == '(' || A[lo] == '{' || A[lo] == '['))
            {
                dp[lo][hi]+=temp;
                 if( dp[lo][hi] >= MOD)
                 {
                     dp[lo][hi] = dp[lo][hi]%MOD;
                     used = true;
                 }

            }
            else if( (A[lo] == '?') && (A[i] == ')' || A[i] == ']' || A[i] == '}'))
            {
                dp[lo][hi]+=temp;
                 if( dp[lo][hi] >= MOD)
                 {
                     dp[lo][hi] = dp[lo][hi]%MOD;
                     used = true;
                 }
            }
        }

    }


    int main()
    {
        long long int MOD = 100000;
        long long int n;
        scanf("%lld",&n);
        lp(i,0,n+1)
            lp(j,0,n+1)
                dp[i][j] = -1;
        scanf("%s",A);
        if( strlen(A) < n)
            n = strlen(A);
        bracket(0,n-1,MOD);
        if( used == true)
            printf("%0.5lld",dp[0][n-1]);
        else
            printf("%lld",dp[0][n-1]);
        return 0;
    }
