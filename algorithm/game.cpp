#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e4+10;
ll dp[61][lim];
int A[61];
int n;
int gcd(int a,int b){
    if(b>a) return gcd(b,a);
    return b==0?a:gcd(b,a%b);
}
ll solve(int pos,int cur)
{
   // cout<<pos<<endl;
    if( dp[pos][cur] != -1ll)
        return dp[pos][cur];
    if( pos == n && cur == 1)
        return 1ll;
    if( pos == n && cur != 1)
        return 0ll;
   // cout<<__gcd(cur,A[pos])<<endl;
    dp[pos][cur] = 1ll*solve(pos+1,cur)+1ll*solve(pos+1,gcd(cur,A[pos]));
    return dp[pos][cur];
}
int main()
{
    //cout<<__gcd(10,0)<<endl;
    int t;
    scan(t);
    while(t--)
    {
        //int n;
        scan(n);
        memset(dp,-1ll,sizeof(dp));
        for(int i=0;i<n;++i)
            cin>>A[i];
        cout<<solve(0,0)<<endl;

    }
    return 0;
}


