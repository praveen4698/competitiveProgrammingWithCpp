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

const int lim = 1e6;
map<char,int> M;
int main()
{
    int n,k;
    string S;
    scan2(n,k);
    cin>>S;
    int cont = 1;
    for(int i=1;i<n;++i){
        if( cont == k){
            M[S[i-1]]++;
            cont = 0;
        }
        if( S[i] == S[i-1]){
            cont++;
        }
        else{
            cont = 1;
        }
    }
    if( cont == k)
        M[S[n-1]]++;

    int ans = 0;
    for(auto m:M){
        ans = max(m.second,ans);
    }
    cout<<ans<<endl;
    return 0;
}
