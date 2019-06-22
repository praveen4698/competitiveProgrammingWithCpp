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
ll curmin,step;
ll sum(ll n){
    ll temp = 0ll;
    while(n){
        temp+=n%10;
        n/=10;
    }
    return temp;
}
void solve(ll n,ll d,int depth){
     
    if( depth > 12)
        return;

    if( n <= curmin){
        // cout<<"SDFS";
        if( n == curmin && step > depth){
            step = depth;
        }
        if( n < curmin){
            curmin = n;
            step = depth;
        }
    }

    solve( sum(n) ,d , depth + 1);
    solve(n+d, d, depth+1);
}
int main()
{
    int t;
    scan(t);
    while(t--){
        ll n,d;
        cin>>n>>d;
        curmin = 100000000000;
        step = 100;
        solve(n,d,0);
        cout<<curmin<<" "<<step<<endl;
    }
    return 0;
}
