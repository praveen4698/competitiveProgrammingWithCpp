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

// color 0 = white
// color 1 = Black
ll white(ll x1,ll y1,ll x2,ll y2,ll color){

    if( x2 < x1 || y2 < y1)
        return 0;
    ll row = (x2-x1+1);
    ll col = (y2-y1+1);
    ll cont = (row/2 + row%2)*(col/2 + col%2) + (row/2)*(col/2);
    if((x1+y1)%2 == 0){
        // cout<<cont<<endl;
        if( color == 0)
            return cont;
        else
            return row*col - cont;
    }
    else{
        if( color == 1)
            return cont;
        else
            return row*col - cont;
    }
}
int main()
{
    int t;
    scan(t);
    while(t--){

        ll x,y;
        cin>>x>>y;
        ll x1,x2,x3,x4,y1,y2,y3,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll ans = white(1,1,x,y,0) + white(x1,y1,x2,y2,1) - white(x3,y3,x4,y4,0) - white(max(x1,x3),max(y1,y3),min(x2,x4),min(y4,y2),1);
        // cout<<white(1,1,x,y,0)<<" "<<white(x1,y1,x2,y2,1)<<" "<<white(x3,y3,x4,y4,0)<<" "<<white(max(x1,x3),max(y1,y3),min(x2,x4),min(y4,y2),1)<<endl;

        cout<<ans<<" "<<x*y-ans<<endl;
    }
   return 0;
}
