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
const int lim = 201;
int sum[lim][lim];
int ans[lim];
int A[lim][lim];

int main()
{
    int n,m;
    scan2(n,m);
    memset(sum,0,sizeof(sum));
    memset(ans,INF,sizeof(ans));
    for(int i=1;i<=n;++i){
        string s;
        cin>>s;
        for(int j=1;j<=m;++j){
            A[i][j] = (s[j-1]-'0');
            if( (i+j)%2 == 1)
                A[i][j]^=1;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + A[i][j];
        }
    }
    for(int k=1;k<=min(n,m);++k){
        for(int i=1;(i+k-1<=n);++i){
            for(int j=1;(j+k-1<=m);++j){
                int temp = sum[i+k-1][j+k-1] - sum[i+k-1][j-1] - sum[i-1][j+k-1] + sum[i-1][j-1];
                ans[k] = min(ans[k],min(k*k-temp,temp));

            }
        }
    }
    int q;
    scan(q);
    while(q--){
        int a;
        scan(a);
        for(int i=min(n,m);i>=0;--i){
            if( a >= ans[i]){
                print(i);
                break;
            }
        }
    }
    return 0;
}
