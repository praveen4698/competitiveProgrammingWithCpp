#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b)
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
vector<int> G[lim];
bool visit[lim];
void DFS(int ver)
{
    if(visit[ver] == true)
        return ;
    visit[ver] = true;
    for(int a:G[ver])
        DFS(a);

}
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,m;
        cin>>n;
        cin>>m;
        memset(visit,false,sizeof(visit));
        for(int i=0;i<=n;++i)
            G[i].clear();
        for(int i=0;i<m;++i)
        {
            int a,b;
            scan2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        int ans = 0;
        if( n == 0)
        {
            cout<<ans<<endl;

        }
        else if( m == 0)
        {
            cout<<n-1<<endl;

        }
        else
        {
            for(int i=1;i<=n;++i)
            {
                if( visit[i] == false)
                {   DFS(i);
                        ans++;
                }
            }
            cout<<ans-1<<endl;
        }
    }
    return 0;
}


