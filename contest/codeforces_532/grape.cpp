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
    int x,y,z;
    scan3(x,y,z);
    int a,b,c;
    scan3(a,b,c);
    if( x > a){
        printf("NO");
        return 0;
    }
    a = a-x;
    if( y > a+b){
        printf("NO");
        return 0;
    }
    int t = a+b-y;
    if(z > t+c){
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}
