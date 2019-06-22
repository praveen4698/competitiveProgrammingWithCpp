#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        cin>>n;
        ll i=1ll;
        ll cont = 0;
        while(i<=n)
        {
            ll val = n/i;
            ll j = n/val + 1;
            cont +=(j-i)*val;
            i = j;
        }
        ll g = __gcd(n*n,cont);
        printf("%lld/%lld\n",cont/g,n*n/g);
    }
    return 0;
}
