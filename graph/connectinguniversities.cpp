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
    vi G[500001];
    int A[500001];
    map<pair<int,int>,int> M;
    pair<int,int> edge[500001];
    int n,k;
    int DFS(int ver ,int par = -1 )
    {
        int sum = 0;
        lp(i,0,G[ver].size())
        {
            if( G[ver][i] != par)
            {
                int t = DFS(G[ver][i],ver);
                M[mp(ver,G[ver][i])] = t;
                M[mp(G[ver][i],ver)] = 2*k - t;
                sum +=t;
            }

        }
        if( A[ver] == 1)
            sum++;
        return sum;


    }

    int main()
    {
        scan2(n,k);
        lp(i,0,2*k)
         {
             int a;
             scanf("%d",&a);
             A[a] = 1;
         }

        lp(i,0,n-1)
        {
            int a,b;
            scan2(a,b);
            G[a].pb(b);
            G[b].pb(a);
            edge[i].first = a;
            edge[i].second = b;
        }
        int de = DFS(1);
        long long int ans = 0;
        for(int i = 0;i<n-1;++i)
        {
            int a = edge[i].first;
            int b = edge[i].second;
            ans+=(long long int)min(M[mp(a,b)],M[mp(b,a)]);
        }
        cout<<ans;
        return 0;
    }
