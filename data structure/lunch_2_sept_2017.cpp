#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int G[7][7];
    int Acq[10];
    int ans[10];
    int A[1001];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                scanf("%d",&A[i]);
            }
            for(int i=1;i<7;++i)
                for(int j=1;j<7;++j)
                    G[i][j] = 0;
            int flag = 0;
            for(int i=1;i<7;++i)
            {
               // int prev = -1;
                for(int j=1;j<n;++j)
                {
                   // if( A[j] != i)
                    //    continue;
                  //  if(prev == -1)
                   // {
                   //     prev = j;
                    //    continue;
                    //}
                    if( A[j] == A[j-1])
                            flag = 1;
                   // prev = j;
                }
            }
            if(flag == 1)
            {
                printf("-1\n");
                continue;
            }
            for(int i=1;i<=6;++i)
                G[i][i] = 2;
            for(int i=1;i<n;++i)
            {
                G[A[i]][A[i-1]] = 2;
                G[A[i-1]][A[i]] = 2;
                //printf("%d\n",A[i],A[i-1])
            }
            flag = 0;
            for(int i=1;i<7;++i)
            {
                for(int j=1;j<7;++j)
                {
                    if( i == j)
                        continue;
                    for(int k=1;k<7;++k)
                    {
                        if( k == i || k == j)
                            continue;
                        for(int l=1;l<7;++l)
                        {
                            if(l == k || l == j || l == i)
                                continue;
                            for(int m=1;m<7;++m)
                            {
                                if( m == l || m == k || m == j || m == i)
                                    continue;
                                for(int N=1;N<7;++N)
                                {
                                    if( N == m || N == l || N == k || N == j || N == i)
                                        continue;
                                    if( flag == 1)
                                            break;

                                    if( G[i][j] == 0 && G[k][l] == 0 && G[m][N] == 0 )
                                    {
                                       // printf("%d %d %d %d %d %d %d\n",i,j,k,l,m,N,G[i][j]);
                                        ans[i] = j;
                                        ans[j] = i;
                                        ans[k] = l;
                                        ans[l] = k;
                                        ans[m] = N;
                                        ans[N] = m;
                                        flag = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if( flag == 1)
            {
                for(int i=1;i<7;++i)
                    printf("%d ",ans[i]);
            }
            else
                printf("-1");
            printf("\n");
        }
        return 0;
    }
