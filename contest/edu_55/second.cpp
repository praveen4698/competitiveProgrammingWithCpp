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
    int t;
    scan(t);
    while(t--){
        ll n,x,y,d;
        cin>>n>>x>>y>>d;
        if( abs(y-x)%d == 0){
            cout<<abs(y-x)/d<<endl;
        }
        else if( d >= n-1){
            if( x == y){
                cout<<0<<endl;
            }
            else if( y == n || y == 1){
                cout<<1<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            bool flag = false;
            ll t1 = INFL;
            if( (n-y)%d == 0ll){
                t1 = (n-x)/d + ((n-x)%d>=1) + (n-y)/d;
                flag = true;
            }
            ll t2 = INFL;
            if( (y-1)%d == 0ll){
                t2 = (x-1)/d + ((x-1)%d>=1) + (y-1)/d;
                flag = true;
            }
            if( flag == true)
                cout<<min(t1,t2)<<endl;
            else
                cout<<-1<<endl;

        }
    }
    
    return 0;
}