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
            long long int x,y;
            scanf("%lld %lld",&x,&y);
            long long int ans = (((x+y)*(x+y+1))/2) + x+1;
            printf("%lld\n",ans);
        }
        return 0;
    }
