#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vector<ll> prime;
    const int lim = 2e6;
    int A[lim];
    void preprocess()
    {
        memset(A,0,sizeof(A));
        for(int i=2;i<lim;++i)
        {
            if( A[i] == 0)
            {
                for(int j=2*i;j<lim;j = i+j)
                {
                    A[j] = 1;
                }
            }
        }
        for(int i=2;i<lim;++i)
            if( A[i] == 0)
                prime.push_back(i*1LL);
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        preprocess();
        while(t--)
        {
            ll n;
            cin>>n;
            ll ans = 0;
            for(ll a:prime)
            {
               // cout<<a<<"\n";
                while(n%a == 0)
                {
                    ans = max(ans,a);
                    n = n/a;
                }
            }
            ans = max(n,ans);
            cout<<ans<<"\n";
        }
        return 0;
    }
