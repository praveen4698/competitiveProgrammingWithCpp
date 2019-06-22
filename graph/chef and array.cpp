#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[100001];
    int main()
    {

        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i =0;i<n;++i)
                scanf("%d",&A[i]);
            int mini = INF;
            while(1)
            {
                int temp = INF;
                for(int i =0;i<n;++i)
                {
                    if( temp > A[i])
                        temp = A[i];
                }
                if( temp == mini)
                    break;
                mini = temp ;
                for(int i=0;i<n;++i)
                {
                    if(A[i]%mini == 0)
                        A[i] = mini;
                    else
                        A[i] = A[i]%mini;
                }
            }
            long long int ans =0;
            for(int i =0;i<n;++i)
                ans+=A[i];

            printf("%lld\n",ans);
            }
        return 0;
    }
