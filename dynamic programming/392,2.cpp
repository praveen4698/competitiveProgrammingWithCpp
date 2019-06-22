#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
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
    const int lim = 1e5 + 10;
    vi P[lim];
    int dp[lim];
    void pre_compute()
    {
        lp(i,1,lim)
            P[i].pb(i);

        for(int p = 2;p*p<= lim ;p++)
        {
            if( P[p].size() == 1)
            {
                for(int i= 2*p;i<lim;i = i+p)

                {
                    P[i].pb(p);

                }
            }
        }
        return;
    }
    int main()
    {
        pre_compute();

        lp(i,1,lim)
            dp[i] = 0;

        int n;
        scan(n);
        lp(i,0,n)
        {
            int a;
            scan(a);
            for( int j = 0; j < P[a].size(); j++)
            {
               // printf(" a = %d prime = %d\n",a,P[a][j]);
                dp[P[a][j]]+=1;
            }

        }
           int maxi = 0;
            lp(i,0,lim)
            {
                if( dp[i] > maxi)
                    maxi = dp[i];
            }
            printf("%d\n",maxi);
        return 0;
    }
