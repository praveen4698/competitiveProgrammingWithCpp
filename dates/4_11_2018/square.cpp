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


int main()
{
    int t;
    scan(t);
    while(t--){
        ll a,b;
        cin>>a>>b;
        if( a-b == 1){
            ll p = a+b;
            bool flag = true;
            
            for(ll i=2ll;i*i<=p;++i){

                if( p%i == 0){
                    flag = false;
                }
            }
            if( flag == false){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
        }
        else{
            printf("NO\n");
        }
    }    
    return 0;
}
