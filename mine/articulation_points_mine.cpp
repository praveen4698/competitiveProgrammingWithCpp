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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
set<int> points;
vector<int> G[lim];
bool visited[lim];
int low[lim],in[lim],timer;
void articulation_points(int ver,int par)
{
    low[ver] = in[ver] = timer++;
    visited[ver] = true;
    int children = 0;
    for(int child:G[ver])
    {
        if( child == par)
            continue;
        if( visited[child] == true)
            low[ver] = min(low[ver],in[child]);
        else
        {
            articulation_points(child,ver);
            low[ver] = min(low[ver],low[child]);
            if( low[child] >= in[ver] && par != -1 )
                points.insert(ver);
            children++;
        }
    }
    if(par == -1 && children > 1)
        points.insert(ver);
}

int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,m,k;
        scan3(n,m,k);
        points.clear();
        for(int i=0;i<n+1;++i)
            G[i].clear(),visited[i] = false;
        for(int i=0;i<m;++i)
        {
            int a,b;
            scan2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        timer = 0;
        articulation_points(0,-1);
        cout<<points.size()*k<<endl;
    }
    return 0;
}


