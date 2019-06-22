#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    vector<int> ans;
    vector<int> G[lim];
    map<pair<int,int> ,int > M;
    int dp[lim];
    void DFS(int v,int par = -1)
    {
        dp[v] = 0;
        for(auto c:G[v])
        {
            if( c != par)
            {
                DFS(c,v);
                if( dp[c] == 0 && M[make_pair(c,v)] == 2 && M[make_pair(v,c)])
                {
                    dp[v]+=1;
                    ans.push_back(c);
                }
                else
                    dp[v]+=dp[c];
                }
            }
        }
    }
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;++i)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back(b);
            G[b].push_back(a);
            M[make_pair(a,b)] = c;
            M[make_pair(b,a)] = c;
        }
        DFS(1);
        printf("%d\n",dp[1]);
        for(int i=0;i<dp[1];++i)
        {
            printf("%d ",ans[i]);
        }
        return 0;
    }

