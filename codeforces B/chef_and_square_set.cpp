#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e2;
    int A[lim];
    vector<int> primes;
    void preprocess()
    {
        memset(A,0,sizeof(A));
        for(int i=2;i<lim;++i)
        {
            if(A[i] == 0)
            {
                for(int j=2*i;j<lim;j=j+i)
                    A[j] = 1;
            }
        }
        for(int i=2;i<lim;++i)
            if(A[i]==0)
                primes.push_back(i);
    }
   // int S[1000001],cont[1000001]
    int main()
    {
        int t;
        scanf("%d",&t);
        preprocess();
        map<int,int> M;
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                int a;
                cin>>a;
                for(int p:primes)
                {

                    int temp = 0;
                    while(a%p ==0)
                    {
                        temp++;
                        a/=p;

                    }
                    if(temp%2 == 1)
                        M[p]++;
                    if( a <= 1)
                        break;
                    if( p > a)
                         break;
                }
                if(  a > 1)
                    M[a]++;
            }
            ll ans = 0;
            for(auto m:M)
            {
                ans+=min(1ll*(n-m.second),1ll*m.second);
            }
            cout<<ans<<"\n";
            M.clear();
        }
        return 0;
    }
