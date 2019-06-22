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
ll A[lim];
int main()
{
    int n,m;
    scan2(n,m);
    ll d;
    cin>>d;
    ll cost = 0;
    A[0] = -1;
    A[n+1] = -1;
    for(int i=1;i<n+1;++i){
        cin>>A[i];
    }
    for(int i=1;i<=n;++i){
        if( A[i] > d && A[i-1] <= d)
            cost++;
    }
    while(m--){
        int t;
        scan(t);
        if( t == 0){
            cout<<cost<<endl;
        }
        else{
            ll a,b;
            cin>>a>>b;
            A[a]+=b;
            if( A[a] > d && (A[a]-b) <= d){
                if( A[a-1] <= d && A[a+1] <=d ){
                    cost++;
                }
                else if( A[a-1] > d && A[a+1] > d){
                    cost--;
                }
                
            }
            // cout<<cost<<" SDFS"<<endl;
        }
    }
    return 0;
}
