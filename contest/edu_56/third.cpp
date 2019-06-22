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
ll B[lim];
ll A[lim];

int main()
{
    int n;
    scan(n);
    for(int i=1;i<=n/2;++i){
        cin>>B[i];
    }
    A[1] = 0;
    ll l = 0ll;
    A[n] = B[1];
    ll r = 1ll*A[n];
    for(int i=2;i<=n/2;++i){
       
        if( l+r <= B[i]){
            l+=(B[i]-l-r);
        }
        else{
            r-=(r+l-B[i]);
        }
        A[i] = l;
        A[n-i+1] = r;

    }
    for(int i=1;i<=n;++i){
        cout<<A[i]<<" ";
    }
    return 0;
}
