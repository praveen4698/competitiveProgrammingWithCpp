#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            if( n%4 == 0)
            {
                printf("%d\n",n/4);
            }
            else if( n%4 == 1)
            {
                if( n-9 >= 0)
                {
                    printf("%d\n",(n-9)/4 + 1);

                }
                else
                    printf("-1\n");
            }
            else if( n%4 == 2)
            {
                if( n-6 >= 0)
                    printf("%d\n",(n-6)/4 + 1);
                else
                    printf("-1\n");
            }
            else
            {
                if( n-15 >= 0)
                    printf("%d\n",(n-15)/4 + 2);
                else
                    printf("-1\n");
            }
        }
        return 0;
    }
