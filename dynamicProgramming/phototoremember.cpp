#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e6+10;
    long long int w[lim],h[lim];
    int main()
    {
        int n;
        scanf("%d",&n);
        long long int sum = 0;
        long long int maxi = -1,maxi2=-1;
        for(int i=0;i<n;++i)
        {
            cin>>w[i]>>h[i];
            sum+=w[i];
            if(h[i] > maxi)
            {
                maxi2 = maxi;
                maxi = h[i];
            }
            else if( h[i] > maxi2)
            {
                maxi2 = h[i];
            }
        }
        for(int i=0;i<n;++i)
        {
            long long int ans = 0;
            if( h[i] == maxi)
            {
                ans = maxi2*(sum-w[i]);
            }
            else
                ans = maxi*(sum-w[i]);
            cout<<ans<<" ";
        }
        return 0;
    }
