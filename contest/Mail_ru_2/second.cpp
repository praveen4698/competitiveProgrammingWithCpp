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
const int lim = 1000+10;

int main()
{
    int A[lim];
    int B[lim];
    int n;
    scan(n);
    int s;
    cin>>s;
    for(int i=1;i<=n;++i){
        scan(A[i]);
    }
    for(int i=1;i<=n;++i){
        scan(B[i]);
    }
    if( A[1] == 0 || (A[s] == 0 && B[s] == 0)){
        printf("NO\n");
        return 0;
    }
    if( A[s] == 1){
        printf("YES\n");
        return 0;
    }
    for(int i=s;i<=n;++i){
        if( A[i] == 1 && B[i] == 1){
            printf("YES\n");
            return 0;
        } 
    }
    printf("NO\n");
    return 0;
}
