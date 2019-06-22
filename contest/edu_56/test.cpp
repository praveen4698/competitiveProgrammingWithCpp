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
const ll MOD = 1e9+7;
const ll mod = 998244353;
const int lim = 1e6;
vector<int> G[lim];
int value[lim];
ll ans ;
void DFS(int ver,int currsum){
    if(ans == -1)
        return;
    if( value[ver] != -1){
        if(value[ver] >= currsum){
            ans+=(value[ver]-currsum);
            currsum = value[ver];
        }
        else {
            ans = -1;
            return ;
        }
    }
    for(int v:G[ver]){
        DFS(v,currsum);
    }
}
int main()
{
    int n;
    scan(n);
    for(int i=2;i<n+1;i++){
        int a;
        scan(a);
        G[a].push_back(i);
    }
    for(int i=1;i<n+1;++i){
        scan(value[i]);
    }
    ans = 0;
    DFS(1,0);
    cout<<ans<<endl;

    return 0;
}
