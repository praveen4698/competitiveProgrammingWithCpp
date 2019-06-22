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
const int lim = 101;
int A[101];
int main()
{
    memset(A,0,sizeof(A));
    int mini = INF;
    int n;
    scan(n);
    int cost = 0;
    int ans = 0;
    for(int i=0;i<n;++i){
        int a;
        scan(a);
        A[a]++;
        mini = min(mini,a);
        cost+=a; 
    }
    ans = cost;
    for(int i=1;i<=100;++i){
        if( A[i] > 0){
            for(int j=1;j<=i;++j){
                if( i%j == 0){
                    int temp = cost - i + i/j + mini*(j) - mini;
                    ans = min(ans,temp);
                    // cout<<ans<<" "<<i<<" "<<j<<endl;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
