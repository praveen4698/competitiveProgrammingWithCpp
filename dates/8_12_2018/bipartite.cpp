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
const int lim = 1e6+10;
int parent[lim];
int par(int x){
    if( parent[x] == -1)
        return x;
    return (parent[x] = par(parent[x]));
}

int main()
{
    set<int> s;
    memset(parent,-1,sizeof(parent));
    int n,m,k;
    scan3(n,m,k);
    while(k--){
        int a,b;
        scan2(a,b);
        b+=n;
        int fa = par(a);
        int fb = par(b);
        // cout<<fa<<" asafaf "<<fb<<endl;
        if(fa == fb)
            continue;
        parent[fa] = fb;
    }
    
    for(int i=1;i<=m+n;++i){
        // cout<<par(i)<<endl;
        s.insert(par(i));
    }
    cout<<s.size()-1<<endl;
    return 0;
}
