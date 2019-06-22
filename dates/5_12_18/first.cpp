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
int L[lim],R[lim];


int main()
{
    string S;
    int n;
    scan(n);
    cin>>S;
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    for(int i=0;i<n;++i){
        if( S[i] == 'G'){
            L[i+1] = L[i] + 1;
        }
        else{
            L[i+1] = 0;
        }
    }
    int cont = 0;
    for(int i=n-1;i>=0;--i){
        if( S[i] == 'G'){
            R[i+1] = R[i+2] + 1;
            cont++;
        }
        else{
            R[i+1] = 0;
        }
    }
    int ans = -1;
    if( L[n] == n){
        cout<<n<<endl;
        return 0;
    }
    for(int i=0;i<n;++i){
        if( S[i] == 'S')
            ans = max(ans,L[i]+R[i+2]+1);
    }
    ans = min(ans,cont);
    cout<<ans<<endl;
    return 0;
}
