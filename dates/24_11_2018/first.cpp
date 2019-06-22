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

map<int,int> M;
vector<int> A;
int main()
{
    int n;
    scan(n);  

    for(int i=0;i<n;++i){
        int a;
        scan(a);
        M[a]++;
    }

    for(auto m:M){
        A.push_back(m.second);
    }

    sort(all(A));
    n = A.size();
    int ans = 0;
    int tt = A[n-1];

    for(int i=1;i<=tt;++i){

        int temp = 0;
        auto itr = A.begin();
        int k = i;

        while(A[n-1] >= k){

            itr = lower_bound(itr,A.end(),k);
            temp+=k;

            if( itr == A.end()-1){
                break;
            }

            k*=2;
            itr++;
           
        }

        ans = max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
