#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%lld",&a)
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
    int t;
    cin>>t;
    while(t--) {
        int n;
        scanf("%d",&n);
        vector<ll> A;
        for(int i=0;i<n; ++i) {
            ll a;
            cin>>a;
            A.push_back(a);
        }
        ll ans = 0ll;
        while(A.size() > 1){
            ll mini = A[0]+A[A.size()-1];
            // cout<<A.size()<<endl;
            for(int i=0;i<A.size()-1;++i) {
                mini = min(A[i]+A[i+1],mini);
            }
            // cout<<mini<<endl;
            int m = A.size();
            for(int i=0;i<A.size()-1;++i) {
                if( i == 0 &&  (mini == A[0]+A[A.size()-1])){
                    ans = ans + mini;
                    // cout<<i<<endl;
                    A[i] = mini;
                    A.pop_back();
                    break;
                }
                if( mini == A[i]+A[i+1]){
                    ans = ans + mini;
                    // cout<<i<<endl;
                    A[i] = mini;
                    if( i+1 == A.size() -1) {
                        A.pop_back();
                    }
                    else 
                        A.erase(A.begin()+i+1,A.begin()+i+2);
                    // cout<<A.size()<<endl;
                    break;
                }
            }
            int m2 = A.size();
            assert(m != m2);
            // break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
