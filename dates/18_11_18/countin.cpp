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
        int n,k;
        scan2(n,k);
        int sum = 0;
        for(int i=1;i<=n;++i){
            int a;
            scan(a);
            if( i&1 ){
                if( sum > 0)
                    sum+=a;
                else
                    sum-=a;
            }
            else{
                if( sum > 0)
                    sum-=a;
                else
                    sum+=a;

            }
        }
        sum = abs(sum);
        if( sum >= k)
            cout<<"1"<<endl;
        else
            cout<<"2"<<endl;
    }
    return 0;
}
