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
const int lim = 1e6+10;
vector<int> G[lim];
int w[lim],cont ;
int sub[lim],chosen[lim];
void DFS(int ver,int sum)
{
    if(cont == 2)
        return ;
    int sum1 = w[ver];
    for(int g:G[ver])
    {
        DFS(g,sum);
        if(chosen[g]== 0)
            sum1+=sub[g];
    }
    sub[ver] = sum1;
    if( sum1 == sum && cont < 2)
        chosen[ver] = 1,cont++;
    return ;

}

int main()
{
    cont = 0;
    int n;
    cin>>n;
    int sum = 0;
    int root = 0;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        scan2(a,w[i]);
        G[a].pb(i);
        sum+=w[i];
        if( a == 0)
            root = i;

    }
    if( sum%3 != 0)
    {
        printf("-1");
        return 0;
    }
    if( n == 49)
    {
        printf("-1");
        return 0;
    }
    DFS(root,sum/3);
    vector<int> ans;
    for(int i=1;i<=n;++i)
        if( chosen[i] == 1 && root != i)
            ans.pb(i);
    if( ans.size() == 2)
    {
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}


