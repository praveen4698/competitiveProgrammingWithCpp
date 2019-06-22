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
            int a,b,m;
            scanf("%d %d %d",&a,&b,&m);
            printf("%d\n",(b/m) - (a-1)/m);
        }
        return 0;
    }
