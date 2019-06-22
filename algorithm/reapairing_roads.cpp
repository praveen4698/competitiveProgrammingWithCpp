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
const int lim = 1e4 +10;
vector<int> G[lim];
//int cont[lim];
bool leaf[lim];
int ans = 0;
void DFS(int ver,int par = -1)
{
    bool temp = true;
    for(int child:G[ver])
    {
        if( child != par)
        {
            temp = false;
            DFS(child,ver);
        }
    }
    leaf[ver] = temp;
}
void DFS2(int ver,bool root = true, int par = -1)
{
    int temp = 0;
    for(int child:G[ver])
    {
        if(leaf[child] == true || child == par)
            continue;
        temp++;
        DFS2(child,false,ver);
    }
    if( root == true)
        ans+=(temp+1)/2;
    else
        ans+=(temp)/2;
}
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n;
        scan(n);
        for(int i=0;i<=n;++i)
            G[i].clear();
        memset(leaf,false,sizeof(leaf));
        int cont = 0;
        for(int i=1;i<n;++i)
        {
            int a,b;
            scan2(a,b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        DFS(0);
        for(int child:G[0])
        {
            if( leaf[child] == false)
                cont++;
        }

        ans = 0;
        if( n == 1)
            cout<<"0"<<endl;
        else if( cont == 0)
            cout<<"1"<<endl;
        else
        {
            DFS2(0);
            cout<<ans<<endl;
        }
    }
    return 0;
}


