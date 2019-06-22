#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    ll dp[300001][201];
    ll sum[300001],A[300001],M[201];
    ll solve(int lo,int hi,int turn)
    {
        //cout<<"YO\n";
        if( M[turn] == 1)
        {

          //  printf("%d %d \n",lo,hi);
            ll maxi = -1000;
            lp(i,lo,hi+1)
             maxi = max(maxi,A[i]);
         //   cout<<maxi<<"\n";
             return maxi;

        }

        if( turn%2 == 1)
        {
            ll temp = sum[hi] - sum[hi - M[turn]];
            lp(i,lo+M[turn+1],hi)
            {
              //  cout<<"YO2\n";
                if(dp[i][turn + 1] == -1000)
                {
                    dp[i][turn+1] = solve(i-M[turn+1]+1,i,turn+1);
               //     cout<<"YO3\n";
                }
                dp[hi][turn] = min(dp[hi][turn],temp + dp[i][turn+1]);
            }
        }
        else
        {
            ll temp = sum[hi] - sum[hi-M[turn]];
            lp(i,lo+M[turn+1],hi)
            {
                if( dp[i][turn+1] == 1000)
                {
                    dp[i][turn+1] = solve(i-M[turn+1]+1,i,turn+1);
                }

                dp[hi][turn] = max(dp[hi][turn],dp[i][turn+1]- temp);
            }

        }
        return dp[hi][turn];
    }

    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            int n,m;
            scan2(n,m);
            lp(i,1,m+1)
            {
                lp(j,1,n+1)
                {
                    if( i%2 == 1)
                        dp[j][i] = 1000;
                    else
                        dp[j][i] = -1000;
                }
            }
            lp(i,1,n+1)
                scan(A[i]);
            lp(i,1,m+1)
                scan(M[i]);
            sum[0] = 0;
            lp(i,1,n+1)
                sum[i] = sum[i-1] + A[i];
            ll ans = -1000;
            lp(i,M[1],n+1)
            {
                if(dp[i][1] == 1000)
                    dp[i][1] = solve(i-M[1]+1,i,1);

                ans = max(ans,dp[i][1]);
            }
            lp(i,1,m+1)
            {
                lp(j,1,n+1)
                {
                 //  printf("%lld ",dp[j][i]);
                }
              //  printf("\n");
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
