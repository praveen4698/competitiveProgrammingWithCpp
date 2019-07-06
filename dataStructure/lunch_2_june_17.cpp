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
            int a,b,n;
            scanf("%d %d %d",&a,&b,&n);
            if( n%2 == 1)
                a = a*2;
            printf("%d\n",max(a,b)/min(a,b));

        }
        return 0;
    }
