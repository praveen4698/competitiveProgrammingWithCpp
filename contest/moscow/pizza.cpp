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

vector<int> A;
vector<int> diff;
int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        A.clear();
        A.resize(n);
        diff.clear();
        for(int i=0;i<n;++i){
            scan(A[i]);
        }
        for(int i=0;i<n-1;++i){
            diff.push_back( A[i+1] - A[i] );
        }
        int temp = 360 - A[n-1] + A[0];
        diff.push_back(temp);
        int hcf = __gcd(diff[0],diff[1]);
        for(int i=2;i<diff.size();++i){
            hcf = __gcd(hcf,diff[i]);
        }
        int ans = 0;
        for(int i:diff){
            // cout<<i<<" "<<hcf<<endl;
            ans = ans + i/hcf - 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
