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
const int mod = 998244353;
const int lim = 1e6+10;
vector<int> G[lim];
int dist[lim];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1%mod;
	while(b){
		if(b&1) x = mul(x, a);
		a = mul(a,a);
		b >>= 1;
	}
	return x;
}
int cont[3];
bool DFS(int ver,int par){
    if( dist[ver] == 0)
        return false ;
    for(int child:G[ver]){
        if( child == par){
            continue;
        }
        if( dist[ver] == 0)
            return  false;

        if( dist[child] == -1){
            if( dist[ver] == 1)
                dist[child] = 2;
            else 
                dist[child] = 1;
            cont[dist[child]]++;
            if( !DFS(child,ver))
                return false;
        }
        else if( dist[child] == 0|| dist[ver] == dist[child]){
            dist[child] = dist[ver] = 0;
            return false;
        }
        
    }
    if( dist[ver] == 0)
        return false;
    return true;
}
int main()
{
    int t;
    scan(t);
    while(t--){
        int n,m;
        scan2(n,m);
        for(int i=1;i<=n;++i){
            dist[i] = -1;
            G[i].clear();
        }
        for(int i=0;i<m;++i){
            int a,b;
            scan2(a,b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int ans = 1;
        for(int i=1;i<=n;++i){
            if( dist[i] == -1)
            {
                dist[i] = 1;
                cont[1] = cont[2] = 0;
                cont[1] = 1;
                if(!DFS(i,-1)){
                    ans = 0;
                    // cout<<"SF"<<endl;
                    break;
                }
                //  cout<<cont[1]<<cont[2]<<endl;
                int temp = add(powr(2,cont[2]),powr(2,cont[1]));
                //  cout<<temp<<endl;
                ans = mul(temp,ans);
                //  cout<<ans<<endl;

            }
        }
        
        
        
        cout<<ans<<endl;
    }
    return 0;
}
