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
const int lim = 20001;

vector<int> A,B;
vector<int> arange,brange;

int main()
{
    int n,m;
    scan2(n,m);
    A.resize(n);
    arange.resize(n+1);
    B.resize(m);
    brange.resize(m+1);
    for(int i=0;i<n;++i){
        scan(A[i]);
        arange[i+1] = INF;
    }
    for(int i=0;i<m;++i){
        scan(B[i]);
        brange[i+1] = INF;
    }
    for(int i=0;i<n;++i){
        int temp = 0;
        for(int j=i;j<n;++j){
            temp+=A[j];
            arange[j-i+1] = min(temp,arange[j-i+1]);
        }
    }
    for(int i=0;i<m;++i){
        int temp = 0;
        for(int j=i;j<m;++j){
            temp+=B[j];
            brange[j-i+1] = min(temp,brange[j-i+1]);
        }
    }
    ll x;
    cin>>x;
    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if( arange[i]*1ll*brange[j] <= x){
                // printf("%d %d %d %d\n",i,j,arange[i],brange[j]);
                ans = max(ans,j*i);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
