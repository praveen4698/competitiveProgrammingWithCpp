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

int main()
{

    int t;
    scan(t);
    while(t--)
    {
        ll x;
        cin>>x;
        ll ans = INFL;
        ll i = 0;
        ll cont = 0;
        ll r = 1;
        while(i<x)
        {

            ans = min(ans,cont+abs(x-i));
            cont++;
            i += r;
            r++;
           // cout<<i<<endl;

        }
        //cout<<ans<<endl;
        ans = min(ans,cont+abs(x-i));
        cout<<ans<<endl;

    }
    return 0;
}


