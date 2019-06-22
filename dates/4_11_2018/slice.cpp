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
const int lim = 2e5+10;
int h[lim];

int main()
{
    int n,k;
    cin>>n>>k;
    memset(h,0,sizeof(h));
    for(int i=0;i<n;++i){
        int a;
        scan(a);
        h[a]++;
    }
    int ans = 0;
    int sum = 0;
    for(int i=lim-1;i>=0;--i){

        if( i != lim-1){
            h[i]+=h[i+1];
        }

        if( h[i] == n)
            break;
        sum+=h[i];
        if( sum == k){
            sum = 0;
            ans++;
        }
        else if( sum  > k){
            ans++;
            sum = h[i];
        }
    }
    if( sum > 0){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
