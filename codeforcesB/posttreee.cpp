#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e6;
    ll ans[lim],value[lim];
    int level[lim],st[lim];
    vector<int> G[lim];
    int n;
    void DFS(int ver,int par =0)
    {
        cout<<"sadg";
        level[ver] = level[par] + 1;
        st[ver] = par;
        while(st[ver] > 0 && value[st[ver]] >= value[ver])
        {
            st[ver] = st[st[ver]];
            cout<<"sg";
        }
        ans[ver] = value[ver]*1LL*(level[ver] - level[st[ver]]) + ans[st[ver]];
        for(int u:G[ver])
            DFS(u,ver);
    }

    int main()
    {
        cin>>n;
        memset(ans,0LL,sizeof(ans));
        for(int i=2;i<n+1;++i)
        {
            int a;
            cin>>a;
            G[a].push_back(i);

        }
        for(int i=1;i<n+1;++i)
            cin>>value[i];
        DFS(1);
        for(int i=1;i<n+1;++i)
            printf("%lld ",ans[i]);
        return 0;
    }
