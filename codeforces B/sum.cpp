#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e7;
    ll cont[lim],ans[lim];
    int main()
    {
        memset(cont,0ll,sizeof(lim));
        memset(ans,0ll,sizeof(ans));
        cont[1] = 1ll;
        cont[2] = 2ll;
        for(int i=3;i<lim;++i)
        {
            int j = i;
            int sum1 = 0;
            int sum2 = 0;
            int k= 0;
            while(j>0)
            {
                int ss = j%10;
                if( ss%2 == 0)
                    sum1+=ss;
                if( ss%2 == 1)
                    sum2+=(ss);
                k++;
                j/=10;
            }
            cont[i] = 1ll*abs(sum1-sum2) + cont[i-1];
        }
        ans[1] = 2;
        for(int i=2;i<1000001;++i)
        {
            ans[i] = ans[i-1] + cont[2*i] + cont[2*i-1] - 2ll*cont[i];
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            cin>>n;
            cout<<ans[n]<<endl;
        }
        return 0;
    }

