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
const int lim = 1e5+10;
vi ans,G[lim];
int n,m,k,parent[lim],dist[lim],flag;
bool visit[lim];

void DFS(int ver,int depth,int par)
{
   // dist[ver] = depth;
    cout<<ver<<endl;
    if( visit[ver] == true)
    {
      cout<<"VS "<<ver<<" "<<par<<endl;
        if( dist[par]-dist[ver] == k && flag == 0)
        {
            flag = 1;
            int temp = ver;
            parent[ver] = par;
            while(1)
            {
                ans.pb(temp);
                temp = parent[temp];
                cout<<"SF "<<temp<<endl;
                if( temp == ver)
                    break;

            }
            return;
        }
        else
            return;
    }
    dist[ver] = depth;
    parent[ver]  = par;
    visit[ver] = true;
    for(int child:G[ver])
    {
        if( child == par)
            continue;
        DFS(child,depth+1,ver);
        if( flag == 1)
            return ;
    }
}
int main()
{
    scan(n);
    k = 2;
    memset(parent,-1,sizeof(parent));
    memset(dist,0,sizeof(dist));
    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;++j)
        {
            if( s[j] == '1')
                G[i].pb(j);
        }


    }
    flag = 0;

    for(int i=0;i<n;++i)
    {
        if( visit[i] == false)
        {

            DFS(i,0,-1);

        }
    }

  //  cout<<ans.size()<<endl;
    reverse(all(ans));
    if( flag == 1)
        for(int a:ans)
            cout<<a+1<<" ";
    else
        cout<<"-1";

    return 0;
}


