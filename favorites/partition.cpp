#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e4;
vector<int> G[lim];
int dis[lim];
void DFS(int ver,int depth)
{
    dis[ver] = depth;
    for(int g:G[ver])
        DFS(g,depth+1);
}
int main()
{
    memset(dis,-1,sizeof(dis));
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        int a;
        scan(a);
        if( a == -1)
            continue;
        G[a].push_back(i+1);
    }
    for(int i=1;i<=n;++i)
        if( dis[i] == -1)
            DFS(i,1);
    int ans = 0;
    for(int i=1;i<=n;++i)
        ans = max(ans,dis[i]);
    cout<<ans<<endl;
    return 0;
}


