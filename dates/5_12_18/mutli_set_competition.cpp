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
const int lim = 1e5+10;
vector<int> A[lim];
ll ans[lim];
int main()
{
    int n,m;
    memset(ans,0ll,sizeof(ans));
    scan2(n,m);
    for(int i=0;i<n;++i){
        int a,b;
        scan2(a,b);
        A[a].push_back(b);
    }
    for(int i=1;i<=m;++i){
        sort(all(A[i]));
        reverse(all(A[i]));
        ll s = 0;
        for(int j=0;j<A[i].size();++j){
            s+=1ll*A[i][j];
            if( s>0){
                ans[j+1]+=s;
            }
            
        }
        
    }
    // cout<<endl<<endl;
    ll ret = 0ll;
    for(int i=1;i<=n;++i){
        ret = max(ret,ans[i]);
    }
    cout<<ret<<endl;
    return 0;
}
