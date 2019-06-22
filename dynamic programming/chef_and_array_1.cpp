#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1001;
    int sum[lim][lim];
    int A[lim][lim];
    int n,m;
    int row_max[lim][lim],dq[lim][2];

    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&A[i][j]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                sum[i][j] = A[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

        int a,b,q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            for(int i=1;i<=n;++i)
            {
                int low = 0,hi = -1;
                for(int j=1;j<=m;++j)
                {
                    while(low <= hi && dq[hi][0] < A[i][j])
                        hi--;
                    hi++;
                    dq[hi][0] = A[i][j];
                    dq[hi][1] = j;
                    if( j >= b)
                    {
                        while(dq[low][1] < j-b+1)
                            low++;
                        row_max[i][j] = dq[low][0];
                    }
                }
            }
            int ans = -1;
            for(int j=b;j<=m;++j)
            {
                int low = 0,hi = -1;
                for(int i=1;i<=n;++i)
                {
                    while(low <= hi && dq[hi][0] < row_max[i][j])
                        hi--;
                    hi++;
                    dq[hi][0] = row_max[i][j];
                    dq[hi][1] = i;
                    if( i >= a)
                    {
                        while(dq[low][1] < i-a+1)
                            low++;
                      //  printf("a=%d b=%d i=%d j=%d: max=%d sum=%d\n", a, b, i, j, dq[low][0], sum[i][j] - sum[i - a][j] - sum[i][j - b] + sum[i - a][j - b]);
                        int temp = dq[low][0]*a*b - (sum[i][j] - sum[i - a][j] - sum[i][j - b] + sum[i - a][j - b]);
                        if( ans < 0 || temp < ans)
                            ans = temp;
                    }
                }
            }
            printf("%d\n",ans);
        }
        return 0;
    }

