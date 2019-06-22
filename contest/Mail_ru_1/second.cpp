#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printfn("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

void pr(){
    printf("-1\n");
}

int main()
{
    ll n;

    scanf("%lld",&n);
    ll f = 0;
    ll maximum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        scanf("%lld",&x);
        if (x > maximum)
        {
            f = 1;
            ans = i;
            break;
        }
        maximum = max(maximum, x + 1);
    }
    if (f == 1){
        printf("%lld",ans+1);
    }
    else{
        pr();
    }
    return 0;
}

