#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const long long int lim = pow(2,32) - 1;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long long int n;
            scanf("%lld",&n);
            long long int r = lim%(n+3);
            long long int q = lim/(n+3);
            printf("100000 ");
            for(int i=0;i<r;++i)
                printf("%lld ",q+1);
            for(int i=0;i<n-r-1;++i)
                printf("%lld ",q);
            printf("\n");

        }
        return 0;
    }
