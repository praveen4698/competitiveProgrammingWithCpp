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
            int n,m;
            scanf("%d %d",&n,&m);
            for(int i=0;i<m;++i)
            {
                int a,b;
                scanf("%d %d",&a,&b);
            }
            if( (n-2*m)%2 == 0)
                printf("yes\n");
            else
                printf("no\n");

        }
        return 0;
    }
