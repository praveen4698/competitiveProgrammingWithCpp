#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    ll mod = 1e9+7;
    ll power(ll x, ll n)
    {
        if( n == 0)
            return 1LL;
        ll t = power(x,n/2);
        if(n&1 == 1)
            return (t*t)%mod*x%mod;
        else
            return t*t%mod;
    }

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            ll n;
            cin>>n;
            ll n1 = (n+1)/2;
            ll n2 = n1;
            if(n%2 == 0)
                n2++;

            ll re = power(2,n1) + power(2,n2) - 2;
            re = re%mod;
            cout<<re<<"\n";

        }
        return 0;
    }
