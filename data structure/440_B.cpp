#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    int A[lim],min1[lim],min2[lim];


    int main()
    {
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<=n;++i)
        {
            min1[i] = INF;
            min2[i] = INF;
        }
        int maxi = -INF;
        int mini = INF;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&A[i]);
            maxi = max(A[i],maxi);
            mini = min(A[i],mini);
            if( i == 0)
                min1[i] = A[i];
            else
                min1[i] = min(A[i],min1[i-1]);
        }
        for(int i=n-1;i>=0;--i)
        {
            if( i == n-1)
                min2[i] = A[i];
            else
                min2[i] = min(A[i],min2[i+1]);
        }
        if( k >= 3)
            printf("%d\n",maxi);
        else if( k == 1)
            printf("%d\n",mini);
        else
        {
            int ans = -INF ;
            for(int i=0;i<n-1;++i)
                ans = max(ans,max(min1[i],min2[i+1]));
            printf("%d\n",ans);
        }
        return 0;
    }
