#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e6 + 10;
    int A[lim];
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            int a;
            scanf("%d",&a);
            A[a]++;
        }
        int ans = 0;
        for(int i=1;i<lim;++i)
        {
            if( A[i] >= 1)
            {
                ans+=A[i];
                for(int j=2*i;j<lim;j=j+i)
                    {
                        A[j] = max(A[j]-A[i],0);
                    }
            }
        }
        printf("%d\n",ans);
        return 0;
    }
