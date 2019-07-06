#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    long long int sumx[lim],sumy[lim],sumz[lim];
    vector<long long int> X,Y,Z;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            X.clear();
            Y.clear();
            Z.clear();
            for(int i=0;i<x;++i)
            {
                long long int a;
                scanf("%lld",&a);
                X.push_back(a);
            }
            for(int i=0;i<y;++i)
            {
                long long int a;
                scanf("%lld",&a);
                Y.push_back(a);
            }
            for(int i=0;i<z;++i)
            {
                long long int a;
                scanf("%lld",&a);
                Z.push_back(a);
            }
            sort(X.begin(),X.end());
            sort(Y.begin(),Y.end());
            sort(Z.begin(),Z.end());
            sumx[0] = X[0];
            for(int i=1;i<x;++i)
                sumx[i] = (X[i]+sumx[i-1])%mod;
            sumy[0] = Y[0];
            for(int i=1;i<y;++i)
                sumy[i]= (Y[i]+sumy[i-1])%mod;
            sumz[0] = Z[0];
            for(int i=1;i<z;++i)
                sumz[i] = (Z[i]+sumz[i-1])%mod;

            long long int ans = 0;
            for(int i=0;i<y;++i)
            {
                int p = upper_bound(X.begin(),X.end(),Y[i]) - X.begin();
                int q = upper_bound(Z.begin(),Z.end(),Y[i]) - Z.begin();
                if( p < 1 || q < 1)
                    continue;
                long long int temp = (sumx[p-1] + 1LL*p*Y[i])%mod;
                temp = (temp*((sumz[q-1] + 1LL*(q)*Y[i])%mod)%mod);
                ans+=temp;
                ans%=mod;
            }
            printf("%lld\n",ans);

        }
        return 0;
    }
