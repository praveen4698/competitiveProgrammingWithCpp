#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b) scanf("%d %d %d",&a,&b,&c)
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

    ll dp[31][31];
    ll coeffi(ll n,ll r)
    {
        if( dp[n][r] != -1)
            return dp[n][r];
        if( r == 0 || r == n)
            return 1;

        if( dp[n-1][r-1] == -1)
            dp[n-1][r-1] = coeffi(n-1,r-1);
        if( dp[n-1][r] == -1)
            dp[n-1][r] = coeffi(n-1,r);
        dp[n][r] = dp[n-1][r] + dp[n-1][r-1];
        return dp[n][r];
    }
    int main()
    {
        ll b,g,t;
        cin>>b>>g>>t;
        lp(i,0,31)
            lp(j,0,31)
                dp[i][j] = -1;
        ll i = 4;
        ll j = t - 4;
        ll counti = 0;
        while( i < t)
        {
            if( i  > b)
                break;
            if( j > g)
            {
                i++;
                j--;
                continue;
            }
            if( j < 1)
                break;

            counti+=( coeffi(b,i)*coeffi(g,j));
           // cout<<coeffi(b,i)<<"\n";
           // cout<<coeffi(g,j)<<"\n";
            i++;
            j--;
        }
        cout<<counti;




        return 0;
    }
