#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e6+10;
    vector<int> G[lim];
    int ans[lim];
    void DFS(int ver,int par=-1)
    {
        ans[ver] = par;
        for(auto i:G[ver])
        {
            if( i == par)
                continue;
            DFS(i,ver);
        }
    }
    int main()
    {
        int n,r1,r2;
        scanf("%d %d %d",&n,&r1,&r2);
        for(int i=1;i<n+1;++i)
        {
            if(i == r1)
                continue;
            int a;
            cin>>a;
            G[a].push_back(i);
            G[i].push_back(a);
        }
        ans[r2] = -1;
        DFS(r2);
        for(int i=1;i<n+1;++i)
        {
            if( ans[i] != -1)
                printf("%d ",ans[i]);
        }
        return 0;
    }
