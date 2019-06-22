#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 4e5+10;
vi G[lim];
int parent[lim];
int diameter[lim],maxidiameter,maxinode,ans[lim];
bool visited[lim];
int par(int x)
{
    if( parent[x] == -1)
        return x;
    return parent[x] = par(parent[x]);
}
void DFS(int ver,int depth = 0, int per = -1)
{
    if( depth > maxidiameter)
    {
        maxidiameter = depth;
        maxinode = ver;
    }
    for(int child:G[ver])
    {
        if( child == per)
            continue;
        DFS(child,depth+1,ver);
    }
}
void DFS2(int ver,int per)
{
    visited[ver] = true;
    for(int child:G[ver])
    {
        if( child == per)
            continue;
        DFS2(child,ver);
    }
}
int main()
{
    int n,m,q;
    scan3(n,m,q);
    memset(parent,-1,sizeof(parent));
    memset(diameter,0,sizeof(diameter));
    memset(ans,0,sizeof(ans));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<m;++i)
    {
        int a,b;
        scan2(a,b);
        G[a].pb(b);
        G[b].pb(a);
        int fa = par(a);
        int fb = par(b);
        parent[fb] = fa;
    }

    for(int i=1;i<=n;++i)
    {
        if( visited[i] == false  )
        {
            visited[i] = true;
            maxidiameter = -1;
            DFS(i);
            maxidiameter = -1;
            DFS(maxinode);
            ans[par(i)] = maxidiameter;
            DFS2(i,-1);
        }
    }
    while(q--)
    {
        int a;
        scan(a);
        if( a == 1)
        {
            int b;
            scan(b);
            int fb = par(b);
       //     cout<<fb<<endl;
            cout<<ans[fb]<<endl;
        }
        else
        {
            int b,c;
            scan2(b,c);
            int fb = par(b);
            int fc = par(c);
          //  cout<<fb<<" "<<fc<<endl;
            if( fb == fc)
                continue;
            parent[fb] = fc;
            int temp = (ans[fc]+1)/2 + (ans[fb]+1)/2 + 1;
            ans[fc] = max(ans[fc],ans[fb]);
            ans[fc] = max(ans[fc],temp);
          //  cout<<ans[fc]<<endl;

        }
    }
    return 0;
}


