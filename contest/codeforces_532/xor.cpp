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
const int lim = 1e7+10;
int sum[lim][2];

int main()
{
    sum[0][0] =1;
    int n;
    int temp = 0;
    ll ans = 0;
    scan(n);
    for(int i=1;i<=n;++i){
        int a;
        scan(a);
        temp ^= a;
        ans += sum[temp][i%2];
        sum[temp][i%2]++;

    }
    cout<<ans<<endl;
    return 0;
}
