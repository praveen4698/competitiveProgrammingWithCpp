#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
const int lim = 1001;
int M[lim][lim];
int ds[lim],de[lim];
vector<int> G[lim];
bool visited[lim];
void BFS1(int ver)
{
    queue<pair<int,int> > Q;
    memset(de,INF,sizeof(de));
    Q.push({ver,0});
    de[ver] = 0;
    while(!Q.empty())
    {
        pair<int,int> t = Q.front();
        Q.pop();
        int dist = t.second + 1;
        for(int a:G[t.first])
        {
            if( de[a] > dist)
             {
                 Q.push({a,dist});
                 de[a] = dist;
             }
        }

    }
}
void BFS2(int ver)
{
    queue<pair<int,int> > Q;
    memset(ds,INF,sizeof(ds));
    Q.push({ver,0});
    ds[ver] = 0;
    while(!Q.empty())
    {
        pair<int,int> t = Q.front();
        Q.pop();
        int dist = t.second + 1;
        for(int a:G[t.first])
        {
            if( ds[a] > dist)
             {
                 Q.push({a,dist});
                 ds[a] = dist;
             }
        }

    }
}

int main()
{
    int n,m,s,e;
    cin>>n>>m>>s>>e;
    memset(M,0,sizeof(M));
    memset(ds,0,sizeof(ds));
    memset(de,0,sizeof(de));
   // memset(visit,false,sizeof(visit));
    for(int i=0;i<m;++i)
    {
        int a,b;
        scan2(a,b);
        M[a][b] = 1;
        M[b][a] = 1;
        G[a].pb(b);
        G[b].pb(a);
    }
    BFS1(e);
    BFS2(s);
    int k = de[s];
   // if( k == ds[e])
   //     cout<<"Sdf"<<endl;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {

       for(int j=i+1;j<=n;++j)
        {
            if( M[i][j] == 0 && M[j][i] == 0 && ds[i]+1+de[j] >= k && de[i]+1+ds[j] >= k)
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}


