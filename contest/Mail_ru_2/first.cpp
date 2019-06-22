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


int main()
{
    ll la,ra,ta;
    ll lb,rb,tb;
    cin>>la>>ra>>ta;
    cin>>lb>>rb>>tb;
    ll ans = 0;
    // if( la == 0 && lb == 0 && ra == 1 && rb == 1 && ta == 2 && tb == 2){
    //     assert(ans == -1);
    //     return 0;
    // }
    if( la > lb){
        
        for(int i=0;i<100000000/2;++i){
        ll t1 = la;
        ll t2 = ra;
        la = la + i*1ll*ta;
        ra = ra + i*1ll*ta;
        ll k = (la-lb)/tb;

        ans = max(ans,min(ra,rb + k*tb) - max(la,lb + k*tb) + 1ll);
        ans = max(ans,min(ra,rb + (k+1ll)*tb) - max(la,lb + (k+1ll)*tb) + 1ll);
        // if( la > 10000000000000000)
        //     break;
        la = t1;
        ra = t2;
            
        }
    }
    else{
        swap(la,lb);
        swap(ra,rb);
        swap(ta,tb);
        for(int i=0;i<100000000/2;++i){
            ll t1 = la;
          ll t2 = ra;
         la = la + i*1ll*ta;
         ra = ra + i*1ll*ta;
         ll k = (la-lb)/tb;
        // cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<endl;
        ans = max(ans,min(ra,rb + k*tb) - max(la,lb + k*tb) + 1ll);
        ans = max(ans,min(ra,rb + (k+1ll)*tb) - max(la,lb + (k+1ll)*tb) + 1ll);
        // cout<<ans<<endl;
        // if( la > 10000000000000000)
        //     break;
        la = t1;
        ra = t2;
        
        }
    
    }
    cout<<ans<<endl;
    return 0;
}
