#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int n,m;
        int a[1001],b[1001];
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d",&b[i]);

        }
        sort(b,b+m);
        reverse(b,b+m);
        int j = 0;
        for(int i=0;i<n;++i)
        {
            if(a[i] == 0)
            {
                a[i] = b[j];
                j++;
            }
        }
        int flag = 0;
        for(int i=1;i<n;++i)
        {
            if( a[i] <= a[i-1])
                flag = 1;
        }
        if( flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }
