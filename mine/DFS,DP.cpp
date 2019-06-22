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
    int n,k;
    ll res = 0;
    vi DFS(int ver ,int par = -1 )
    {
        vi temp(k+1);
        temp[0] = 1;
        lp(i,0,G[ver].size())
        {
            if( G[ver][i] != par)
            {
                vi t = DFS(G[ver][i],ver);
                lp(j,0,k+1)
                   {
                       lp(x,0,k+1)
                       {
                           if( j+x < k+1)
                             res = res + temp[j]*t[x];
                       }
                   }
                lp(j,0,k+1)
                    temp[j]+=t[j];
            }

        }
        lpr(j,k,1)
            temp[j] = temp[j-1];
        temp[0] = 0;

        return temp;
    }

    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            scan2(n,k);
            lp(i,0,n-1)
            {
                int a,b;
                scan2(a,b);
                G[a].pb(b);
                G[b].pb(a);
            }
            DFS(0);
            cout<<res+n<<"\n";
            lp(i,0,n)
            {
                G[i].clear();
            }

        }
        return 0;
    }
