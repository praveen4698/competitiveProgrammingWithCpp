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

ll a,b,c,k;
bool check(ll x)
{
    if( a*x*x + b*x + c >= k)
        return true;
    else
        false;
}
int main()
{

    int t;
    scan(t);
    while(t--)
    {
        cin>>a>>b>>c>>k;
        ll l = 0;
        ll r = 1e10;
        while(l<r)
        {
            ll mid = (l+r)/2;
            //cout<<l<<" "<<r<<endl;
            if( check(mid) == false)
                l = mid+1;
            else
                r = mid;
        }
        cout<<r<<endl;
    }
    return 0;
}


