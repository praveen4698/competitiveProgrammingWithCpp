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
    const int lim = 1e5+10;
    bool visited[lim];
    vi A[lim];
    int dp[lim], ans[lim];
    void DFS(int r)
    {
        visited[r] = true;
        vi::iterator i;
        vi temp;
        temp.pb(0);
        temp.pb(0);
        for(i= A[r].begin();i!=A[r].end();++i)
        {

            if( visited[*i] == false)
            {
                DFS(*i);
                dp[r] = max(dp[r],1+dp[*i]);
                temp.pb(1+dp[*i]);
                ans[r] = max(ans[r],ans[*i]);
            }
        }
        sort(temp.begin(),temp.end());
        int m = temp.size();
        ans[r] = max(ans[r],temp[m-1] + temp[m-2]);
    }

    int main()
    {
        int n;
        scan(n);
        lp(i,0,n-1)
        {
            int a,b;
            scan2(a,b);
            A[a].pb(b);
            A[b].pb(a);

        }
        lp(i,1,n+1)
        {
            dp[i] = 0;
            visited[i] = false;
            ans[i] = 0;
        }
        int r;
        scan(r);
        DFS(r);
        int q;
        scan(q);
        while(q--)
        {
            int a;
            scan(a);
            printf("-- %d\n",ans[a]);
        }
        return 0;
    }
