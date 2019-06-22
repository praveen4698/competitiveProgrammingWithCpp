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

const int lim = 1001;
int A[lim];
int main()
{
    int n;
    scan(n);
    for(int i=0; i<n; i++){
        scan(A[i]);
    }
    int ans = -1;
    int cost = INF;
    for(int t=1;t<=100;t++){
        int temp = 0;
        for(int i=0;i<n;++i){
            int a = A[i] - t -1;
            int b = A[i] - t;
            int c = A[i] - t + 1;
            temp = temp + min(abs(a),min(abs(b),abs(c)));
        }
        if( temp < cost){
            cost = temp;
            ans = t;
        }
    }
    cout<<ans<<" "<<cost<<endl;
    return 0;
}
