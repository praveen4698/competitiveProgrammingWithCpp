#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    char A[2][501];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            scanf("%s",A[0]);
            scanf("%s",A[1]);
            int flag[2];
            flag[0] = -1;
            flag[1] = -1;
            int dot = 0;
            int x = 0;
            for(int i=0;i<n;++i)
            {
                if( A[0][i] == '.')
                    dot++;
                if( A[1][i] == '#')
                    dot++;

            }
            for(int i=0;i<n;++i)
            {
                if( A[0][i] == '#' || A[1][i] == '#')
                {
                    x = i;
                    break;
                }


            }

            for(int i=0;i<2;++i)
            {
                int prev = i;
                int j;
                if( A[i][x] == '#')
                {
                    flag[i] = 0;
                    int temp = n+1;
                    for(j=x;j<n;++j)
                    {
                        if(A[prev][j] == '.' )
                         {
                             temp = j;
                             j = j+n+1;
                         }
                        else if( A[1-prev][j] == '#')
                            prev = 1-prev;
                    }
                    j = temp;
                    while(j<n)
                    {
                        if(A[0][j] == '#' || A[1][j] == '#' )
                            flag[i] = 1;

                        j++;
                    }
                }
            }
           // printf("%d %d\n",flag[0],flag[1]);
            if( flag[0] == 0 || flag[1] == 0)
                printf("yes\n");
            else
                printf("no\n");

        }
        return 0;
    }
