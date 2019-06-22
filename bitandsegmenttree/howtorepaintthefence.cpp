#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    int queryres,A[100001] ;
    char C[100001];
    int cont[200001];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,k;
            scanf("%d %d",&n,&k);

            scanf("%s",C);
            for(int i=0;i<n;++i)
            {
                cont[i] = 0;
                if( C[i] == 'R')
                    A[i] = 1;
                else
                    A[i] = 0;
            }
            int ans = 0;
            int state = 0;
            for(int i=0;i<n;++i)
            {
                int temp = A[i];
                if( i > 0)
                    cont[i]+=cont[i-1];
                temp+=cont[i];
               // printf("%d %d %d\n",temp,A[i],cont[i]);
                if( temp%2 == 1)
                {
                    ans++;
                    cont[i]++;
                    cont[min(i+k,n)]--;
                }


            }
            printf("%d\n",ans);

        }
        return 0;
    }
