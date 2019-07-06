#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e4+10;
    ll  ans[lim];
    int main()
    {
        memset(ans,0ll,sizeof(ans));
        ll sum1 = 0;
        ll sum2 = 0;
        for(int i=1;i<lim;++i)
        {
            sum1+=(i*i);
            sum2+=(i);
            ans[i] = sum2*sum2 - sum1;
        }
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            cout<<ans[n]<<"\n";
        }
        return 0;
    }
