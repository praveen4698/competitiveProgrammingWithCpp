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
    int n,k;
    ll res = 0;
    ll ans = -INFL;
    pair<ll,ll> DFS(int ver ,int par = -1 )
    {
        ll max2 = -INFL;
        ll max1 = -INFL;
        ll sum = 0;
        lp(i,0,G[ver].size())
        {
            if( G[ver][i] != par)
            {
                pair<ll,ll> temp = DFS(G[ver][i],ver);
                if( temp.first > max2)
                {
                    max1 = max2;
                    max2 = temp.first;
                }
                else if( temp.first > max1)
                {
                    max1 =temp.first;
                }
                if( max1 != -INFL && max2 != -INFL)
                    ans = max(ans,max1+max2);
                sum = sum+temp.second;
            }

        }
        return make_pair(max(sum+A[ver],max2),sum+A[ver]);


    }

    int main()
    {
        scan(n);
        lp(i,0,n)
            scanf("%d",&A[i]);
        lp(i,0,n-1)
        {
            int a,b;
            scan2(a,b);
            G[a-1].pb(b-1);
            G[b-1].pb(a-1);
        }
        pair<ll,ll> temp = DFS(0);
        if( ans == -INFL)
            printf("Impossible\n");
        else
            printf("%lld\n",ans);
        return 0;
    }

