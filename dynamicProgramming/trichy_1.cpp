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

    int A[1001],sum[1001],dp[1001];
    int main()
    {

        int n;
        scan(n);
        lp(i,0,1001)
        {
            dp[i] = 1;
            sum[i] = INF;
            A[i] = 0;
        }
        lp(i,0,n)
        {
            int a;
            scan(a);
            A[a]++;
        }

        lp(i,1,1001)
        {
            if( A[i] >= 1)
            {
                if( sum[i] == INF)
                    sum[i] = i;
                if( A[i] > 1)
                {
                    sum[i] = sum[i] + i;
                    dp[i] = dp[i] +1;
                }
                lp(j,i+1,1001)
                {
                    if( A[j] >= 1 && j >= sum[i])
                    {
                       // dp[j] = max(dp[j],dp[i] +1);
                       // sum[j] = min(sum[j],sum[i] +j);
                        if( dp[j] < dp[i]+1)
                        {
                            dp[j] = dp[i]+1;
                            sum[j] = sum[i] + j;
                        }
                    }
                }
            }
        }
        int ans = 0;
        lp(i,1,1001)
        {
            ans = max(dp[i],ans);
          // printf("%d - %d\n",i , dp[i]);
        }

        printf("%d",ans);




        return 0;
    }
