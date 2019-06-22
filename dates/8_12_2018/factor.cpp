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
const ll mod = 1e9+7;
const ll MOD = 998244353;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
const int lim = 1e6+10;
int cont[lim];
int main()
{
    memset(cont,0,sizeof(cont));
    int ans = 0;
    cont[0] = 1;
    int n;
    scan(n);
    for(int i=1;i<=n;++i){
        int a;
        scan(a);
        vector<int> t;
        for(int j=1;j*j<=a;++j){
            if( a%j == 0){
                t.push_back(j);
                if( a/j != j)
                    t.push_back(a/j);
            }
        }
        sort(all(t));
        reverse(all(t));
        for(int aa:t){
            cont[aa] = add(cont[aa],cont[aa-1]);
        }
    }
    for(int i=1;i<=n;++i)
        ans = add(ans,cont[i]);
    print(ans);
    return 0;
}
