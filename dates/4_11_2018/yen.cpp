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


int main()
{
    int a,b;
    const double c = 0.006;
    int n;
    cin>>n;
    double t,k;
    cin>>t>>k;
    int ans = -1;
    double diff = 100000000000.00;

    for(int i=0;i<n;++i){
        double h;
        cin>>h;
        double cost = t - c*h;
        cost = cost - k;
        if( cost < 0.00){
            cost = -1.00*cost;
        }
        // cout<<cost<<" "<<diff<<endl;
        if( cost < diff){
            ans = i;
            diff = cost;
        }
    }
    cout<<ans+1<<endl;
    
    return 0;
}
