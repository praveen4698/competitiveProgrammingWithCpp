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
vector<int> ans[5001];

int main()
{
    int n,m;
    scan2(n,m);
    int a,b,col=1;
    for(int i=0;i<m;++i){
        scan2(a,b);
        if( a == b)
            continue;
        ans[a].push_back(col);
        ans[b].push_back(col);
        col++;
    }
    for(int i=1;i<=n;++i){
        if( ans[i].empty()){
            ans[i].push_back(col);
            col++;
        }
        cout<<ans[i].size()<<endl;
        for(int j:ans[i]){
            cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}
