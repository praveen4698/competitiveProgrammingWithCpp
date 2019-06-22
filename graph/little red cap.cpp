#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        vi* A;
        A = new vi [123456];
        long long int   f[123456],g[123456];
        int n,m;
        cin>>n>>m;
        lp(i,0,m)
        {
            int x,y;
            cin>>x>>y;
            A[x].pb(y);
        }
        lp(i,0,n+1)
        {
            f[i] = 0;
            g[i] = 0;
        }

        f[n] = g[n] = 1;
        for(int i = n-1;i>0;i--)
        {
            for(int j = 0;j< A[i].size();j++)
            {
                f[i] = f[i] + f[A[i][j]];
                g[i] = max(g[i],g[A[i][j]]);
            }

             g[i] = g[i]  + f[i];
        }
        printf("%lld",g[1]);

        return 0;
    }
