#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int mod = 1e6+3;
    int fact[mod],inv[mod];
    int power(int x,int n)
    {
        if( n == 0)
            return 1;
        if( n == 1)
            return x%mod;
        int t = power(x,n/2);
        t = (t*1LL*t)%mod;
        t%=mod;
        if( n%2 == 1)
            return (x*1LL*t)%mod;
        else
            return t;
    }
    int C(int n,int r)
    {
        if( n < r)
            return 0;
        return (fact[n]*1LL*inv[r]*1LL*inv[n-r])%mod;
    }
    int main()
    {
        fact[0] = 1;
        inv[0] = 1;
        for(int i=1;i<mod;++i)
        {
            fact[i] = (fact[i-1]*1LL*i)%mod;
            inv[i] = power(fact[i],mod-2);
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,l,r;
            scanf("%d %d %d",&n,&l,&r);
            int N = n+1;
            int R = r-l+1;
           // printf("%d %d\n",C((N+R-1)/mod,(N-1)/mod),C((N+R-1)%mod,(N-1)%mod));
            long long int ans = C((N+R-1)/mod,(N-1)/mod)*1LL*C((N+R-1)%mod,(N-1)%mod);
            ans%=mod;
            printf("%lld\n",(ans-1+mod)%mod);
        }
        return 0;
    }
