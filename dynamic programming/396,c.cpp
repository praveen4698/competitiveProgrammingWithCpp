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
    const int lim = 1e3 + 10;
    const ll mod = 1e9 + 7;
    ll A[lim][lim],dp[lim];
    int C[30];

    int main()
    {
        int n;
        scan(n);
        string S;
        cin>>S;
        lp(i,0,26)
        {
            scan(C[i]);
        }
        lp(i,0,n)
        {
            int flag = 0;
            int maxi = 10001;
            lp(j,i,n)
            {
                maxi = min( maxi,C[S[j]-'a']);
                if( maxi >= j-i+1  && flag == 0)
                {
                    A[i][j] = (ll)1;

                }
                else
                {
                    A[i][j] = (ll)0;
                    flag = 1;
                }
            }

        }
        lp(i,0,n)
        {
            int n1 = i - C[S[i] -'a'] + 1;
            n1 = max(n1,0);
            dp[i] = 0;
            lp(j,n1,i)
            {
                if( A[j][i] == 1 && )
                    dp[i] = dp[i]+dp[j];
                dp[i] = dp[i]%mod;
            }

        }
        printf("%lld",dp[n-1]);
        return 0;
    }
