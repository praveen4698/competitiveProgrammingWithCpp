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
    int c[500001];
    int n,k;
    ll res = 0;
    ll ans = -INFL;
    int check ;
    pair<int,int> DFS(int ver ,int par = -1 )
    {

        int flag = 0;
        int ans = 0;
        if(c[ver] == check)
            flag = 1;
        lp(i,0,G[ver].size())
        {
            if( G[ver][i] != par)
            {
                pair<int,int> temp = DFS(G[ver][i],ver);
                ans+=temp.second;
                if(flag == 1)
                    continue;
                else if(temp.first > 0)
                    ans++;
            }

        }
        return make_pair(flag,ans);


    }

    int main()
    {
        scan(n);
        lp(i,1,n+1)
            scanf("%d",&c[i]);
        lp(i,0,n-1)
        {
            int a,b;
            scan2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        G[0].pb(1);
        G[1].pb(0);
        c[0] = 1;
        check = 0;
        pair<int,int> temp = DFS(0);
        int ans1 = temp.second;
        c[0] = 0;
        check = 1;
        pair<int,int> temp2 = DFS(0);
        int ans2 = temp2.second;
        printf("%d",min(ans1,ans2));
        return 0;
    }
