#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    ll ans[1000001];
    int main()
    {
        memset(ans,-1ll,sizeof(ans));
        vector<pair<pair<int,int> ,int> > pr;
        for(int n=1;n<1001;++n)
        {
            for(int m=1;m<1001;++m)
            {
                int sum = 2*m*n + 2*m*m;
                if( sum > 10000 )
                        continue;
                if( m*m > n*n)
                {
                    pr.push_back({{m*m-n*n,2*m*n},m*m+n*n});
                    ll pro = (m*m-n*n)*1ll*(2ll*m*n)*1ll*(m*m+n*n);
                    ans[sum] = max(ans[sum],pro);
                }
            }
        }
        for(auto x:pr)
        {
            int a = x.first.first;
            int b = x.first.second;
            int c = x.second;
            for(int i=2;i<1001;++i)
            {
                a = i*a;
                b = i*b;
                c = i*c;
                if( a+b+c < 100001)
                    ans[a+b+c] = max(ans[a+b+c],1ll*a*b*c);
            }
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            cin>>n;
            cout<<ans[n]<<"\n";
        }
        return 0;
    }
