#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,k;
            scanf("%d %d",&n,&k);
            vector<double> x(n+1),y(n+1);
            vector<int> inventory(n+1,0);
            for(int i=1;i<n+1;++i)
                cin>>x[i]>>y[i];
            for(int i=1;i<=n;++i)
            {
                string S;
                cin>>S;
                for(int j=0;j<k;++j)
                {
                    if(S[j] == '1')
                        inventory[i]^=(1<<j);
                }
            }
            vector<vector<double> > dp(1<<k,vector<double>(n+1,-1.0));
            dp[0][0] = 0.0;
            for(int mask=0;mask<1<<k;++mask)
            {
                for(int i=0;i<=n;++i)
                {
                    if(dp[mask][i] > -0.5)
                    {
                        for(int j=0;j<=n;++j)
                        {
                            double &temp = dp[mask|inventory[j]][j];
                            const double maybe = dp[mask][i] + sqrt(pow(x[i]-x[j],2)+ pow(y[i]-y[j],2));
                            if( temp < -0.5 || temp > maybe)
                                temp = maybe;
                        }
                    }
                }
            }
            double ans = dp[(1<<k)-1][0];
            if( ans > -0.5)
                printf("%.10lf\n",ans);
            else
                printf("-1\n");
        }
        return 0;
    }
