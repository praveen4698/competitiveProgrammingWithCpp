#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        string A[51];
        int m;
        scanf("%d",&m);
        for(int i = 0;i<m;++i)
        {
            cin>>A[i];

        }
        int n = A[0].size();

        int maxi[51] ;
        for(int i = 0;i<m;++i)
            maxi[i] = -1;
        maxi[0] = 0;
        for(int i=1;i<m;++i)
        {
            int temp = 0;
            for( int j = 0;j<n;++j)
            {
                int cont = 0;
                for(int k = 0;k <n;++k)
                {

                       // printf("yo\n");
                        if( A[0][k]   == A[i][(k+j)%n] )
                            cont++;

                }
               // printf("%d\n",cont);
                if(cont == n)
                {
                    maxi[i] = j;
                    break;
                }
            }
        }
        int flag = 0;
        for(int i =0;i<m;++i)
        {
           // printf("%d\n",maxi[i]);
            if(maxi[i] == -1)
                flag = 1;
        }
        if(flag == 1)
            printf("-1\n");
        else
        {
            int ans = INF;
            for(int i = 0;i<m;++i)
            {
                int temp = 0;
                for(int j = 0;j<m;++j)
                {
                    int a = maxi[j] - maxi[i];
                    if( a < 0)
                        a = a+ n;
                    temp = temp + a;
                }
                ans = min(ans,temp);
            }
            printf("%d\n",ans);
        }
        return 0;
    }
