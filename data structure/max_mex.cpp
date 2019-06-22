#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e6+10;
    int A[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,k;
            scanf("%d %d",&n,&k);
            for(int i=0;i<lim;++i)
                A[i] = 0;
            for(int i=0;i<n;++i)
            {
                int a;
                scanf("%d",&a);
                A[a] =1;
            }
            int ans = -1;
            for(int i=0;i<lim;++i)
            {
                if( A[i] == 1)
                    continue;
                if( k > 0)
                {
                    k--;
                    continue;
                }
                ans = i;
                break;
            }
            printf("%d\n",ans);
        }
        return 0;
    }

