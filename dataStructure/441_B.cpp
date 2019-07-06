#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    vector<int> ans[lim];
    int main()
    {
        int n,k,m;
        scanf("%d %d %d",&n,&k,&m);
        for(int i=0;i<n;++i)
        {
            int a;
            scanf("%d",&a);
            ans[a%m].push_back(a);
        }
        for(int i=0;i<m;++i)
        {
            if( ans[i].size() >= k)
            {
                printf("Yes\n");
                for(int j=0;j<k;++j)
                {
                    printf("%d ",ans[i][j]);
                }
                printf("\n");
                return 0;
            }
        }
        printf("No\n");
        return 0;
    }

