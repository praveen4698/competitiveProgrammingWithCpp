#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 100010;
    ll int fact[lim],invfact[lim],A[lim],cont[lim];
    long long abso(long long i){
    	if(i>=0) return i%mod;
    	return (i%mod+mod)%mod;
	}
    long long int power(ll int x,ll int y )
    {
        if( y == 0)
            return (ll int)1;
        ll int temp = power(x,y/2)%mod;
        temp = ((long long)temp*temp)%mod;
        if(y%2 == 1)
            return ((long long )temp*x)%mod;
        else
            return temp;

    }
    void factorial()
    {
        ll int i =0;
        fact[0] = 1;
        invfact[0] = 1;
        for(i=1;i<lim;++i)
            fact[i] = ((long long int)fact[i-1]*i)%mod;
        for(i=1;i<lim;++i)
            invfact[i] = power(fact[i],mod-2)%mod;
    }
    ll ans[71];
    long long int ncr(int  n,int r)
    {
        if( n <r)
            return 0LL;
        else
            return ((((fact[n]*1ll*invfact[r])%mod)*invfact[n-r])%mod);
    }
    int sq[101];
    int main()
    {
        factorial();
        int cont[71] ;
        int n;
        memset(cont,0,sizeof(cont));
        memset(ans,0LL,sizeof(ans));
        memset(sq,0,sizeof(sq));
        for(int i=1;i<10;i++)
            sq[i*i] = 1;
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            int a;
            scanf("%d",&a);
            cont[a]++;

        }
        if( cont[1] > 0)
        {
            ans[1] = power(2,cont[1])-1;
            if( ans[1] < 0)
                ans[1]+=mod;
            ans[1]%=mod;

        }
        else
            ans[1] = 1ll;
        if( cont[1] == n)
        {
            printf("%lld",ans[1]);
            return 0;
        }
        ans[1]+=1ll;
        ans[1]%=mod;
        for(int i=2;i<71;++i)
        {
            ll temp = 0;
            for(int r=0;r<=cont[i];)
            {
                temp+=ncr(cont[i],r);
                temp%=mod;
                if( sq[i] == 1)
                    r = r+1;
                else
                    r = r+2;
            }
            ans[i] = temp;
        }
        ll aa=1ll;
        for(int i=1;i<71;++i)
            aa = (aa*ans[i])%mod;
        cout<<aa-1;
        return 0;
    }
