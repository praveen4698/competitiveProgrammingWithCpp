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
#define MOD(a) a%1000000007
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vi A[10001];
    ll dp[10001],in[10001];
    int main()
    {
        int z;
        scan(z);
        while(z--)
        {
            int n,m,s,e;
            scanf("%d %d %d %d",&n,&m,&s,&e);
            lp(i,0,n)
            {
                dp[i] = (ll)0;
                in[i] = (ll)0;
            }
            lp(i,0,m)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                A[a].pb(b);
                in[b]++;
            }
            queue<int> Q;
            lp(i,0,n)
            {
                if(in[i] == 0)
                    Q.push(i);
            }
            dp[s] = 1;
            while(!Q.empty())
            {
                int it = Q.front();
                Q.pop();
                vi::iterator i;
                for(i = A[it].begin();i != A[it].end();++i)
                {
                    dp[*i] = (ll)dp[*i] + (ll)dp[it];
                    MOD(dp[*i]);
                    in[*i]--;
                    if( in[*i] == 0)
                    {
                        Q.push(*i);
                    }
                }
            }
            printf("%lld\n",dp[e]);
            lp(i,0,n)
            {
                A[i].clear();
            }
        }
        return 0;
    }
