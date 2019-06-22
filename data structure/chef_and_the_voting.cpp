#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int S[51],A[51];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            int sum = 0,flag = 0;
            for(int i=1;i<n+1;++i)
            {
                scanf("%d",&A[i]);
                sum+=A[i];
                S[i] = -1;
                if(A[i] >= n)
                    flag = 1;
            }
            if(sum > n|| sum < n || flag == 1)
            {
                printf("-1\n");
                continue;
            }
            for(int i=1;i<n+1;++i)
            {
                int j=1;
                while(A[i]>0)
                {
                    if(S[j] == -1)
                    {
                        //printf("yo\n");
                        S[j] = i;

                        A[i]--;
                    }
                    j++;
                }
            }
            for(int i=1;i<n+1;++i)
            {
                if(S[i] == i)
                {
                    int j=1;
                    while(1)
                    {
                        if(S[j] != S[i] )
                        {
                            swap(S[j],S[i]);
                            break;
                        }
                        j++;
                    }
                }
            }
            for(int i=1;i<n+1;++i)
                printf("%d ",S[i]);
            printf("\n");
        }
        return 0;
    }
