#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
#define pb push_back
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 100;
    vector<long long int> primes;
    bool F[1000001];
    map<long long int,long long int> M;
    void pre()
    {
        memset(F, true, sizeof(F));
        for(int i=2;i*i<lim;++i)
        {
            if( F[i] == true)
            {

                for(int j=2*i;j<=lim;j=j+i)
                    F[j] = false;
            }
        }

        for(int i=2;i<lim;++i)
            if(F[i] == true)
                primes.push_back(1LL*i);

        sort(primes.begin(),primes.end());

    }
    long long int power(long long int x,long long int y)
    {
        if( y == 0)
            return 1LL*1;
        long long int t = power(x,y/2)%mod;
        t = (t*t)%mod;
        if(y%2 == 1)
            return (x*t)%mod;
        else
            return t;
    }

    int main()
    {
        int n;
        scanf("%d",&n);
        pre();
        int z = n;
        while(z--)
        {
            long long int x;
            scanf("%lld",&x);
            for(int i=0;i<primes.size();++i)
            {

                while(x%primes[i] == 0)
                {
                    x = x/primes[i];
                    M[primes[i]]++;
                }
                if( x == 1)
                    break;
            }
            if( x > 1)
                M[x]++;
        }
        long long int ans = 1;
        int  flag = 1;
        map<long long int,long long int>::iterator it;
        for( it=M.begin();it!=M.end();++it)
        {
            long long int x = it->first;
            long long int y = it->second;
            if(y%n != 0)
            {
                flag = 0;
            }
            if( y%(n+1) != 0)
            {
                long long int t = power(x,n+1 - (y%(n+1)));
                ans = (ans*t)%mod;
            }
        }

        if(flag == 1)
            printf("justdoit\n");
        else
            printf("%lld\n",ans);

        return 0;
    }

