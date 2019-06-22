#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int Xor[50001];
    int mark[50001];
    int fir[50001];
    int last[50001];
    int dp[50001];
    int A[50001];
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&A[i]);
        }
        for(int i=0;i<5001;++i)
        {
            last[i]=-1;
            fir[i] = 100000;
            mark[i] = 0;
        }
        Xor[0] = 0;
        for(int i=1;i<n+1;++i)
        {
            if( mark[A[i]] != 1)
                Xor[i] = A[i]^Xor[i-1];
            else
                Xor[i] = Xor[i-1];
            mark[A[i]] =1;
            last[A[i]] = max(i,last[A[i]]);
            fir[A[i]] = min(i,fir[A[i]]);
        }

        dp[0] = 0;
        for(int i = 1;i < n+1;++i)
        {
           // printf("iteration = %d    \n",i);
            int flag = 0;
            int maxi = 0;
            int temp = i;
           // printf("\n%d\n",fir[A[i]]);
            if(fir[A[i]] == temp)
            {
                int j = i+1;
               // printf("i=%d ,first = %d\n",i,fir[A[i]]);
               // printf("ds d   %d\n ",j);
                maxi = last[A[i]];
                while(1)
                {
                  //  printf("%d %d \n",j,maxi);
                    if( j >=  maxi || j == 0 || j == -1 )
                        break;
                    if( i > fir[A[j]]  )
                    {
                        flag =1 ;
                        j = -1;
                    }
                    else if( j == fir[A[j]])
                        maxi = max(maxi ,last[A[j]]);
                   // printf("asfas");
                    j++;
                }
            }
            dp[i] = max(dp[i-1],dp[i]);
         //   printf("maxi =  %d\n",maxi);
            if(flag == 0)
                dp[maxi] = max(dp[maxi],(Xor[maxi]^Xor[i-1])+dp[i-1] );

           // printf("dp[%d] = %d  dp[%d] = %d \n",i-1,dp[i-1],maxi,dp[maxi]);
        }
        printf("%d\n",dp[n]);
        return 0;
    }
