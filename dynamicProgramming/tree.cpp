#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vector<pair<int,int> >  G[i];
    int ans ;
    void DFS(int ver,int sum ,int k,int par = -1)
    {
        int temp = 0;
        for(auto g:G[ver])
        {
            int cost = g.second;
            int child = g.first;
            if( child != par)
            {
                DFS(child,sum+cost,k-1,ver);
            }
            ans = max(ans,sum + (k-1)*cost)
        }
    }
    int main()
    {
        ans = INT_MIN;

        return 0;
    }
