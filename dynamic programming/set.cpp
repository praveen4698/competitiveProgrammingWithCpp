#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int cost[100001],height[100001];
    map<int,vector<int> > M;
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&height[i]);
        }
        int sum = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&cost[i]);
            sum = sum + cost[i];
        }
        set<pair<int,int> > S;
        for(int i=0;i<n;++i)
        {
            M[height[i]].push_back(cost[i]);
            S.insert({cost[i],height[i]});
        }
        int ans = INT_MAX;
        for(auto it= M.rbegin(); it != M.rend();++it)
        {
            int hi = it->first;
            vector<int> costi = it->second;
            int temp = 0;
            for(int i=0;i<costi.size();++i)
            {
                S.erase({hi,costi[i]});
                temp+=costi[i];
            }
            set<pair<int,int> >::iterator it = S.rbegin();
            for(int i=0;i<costi.size();++i)
            {
                if(it != S.rend())
                {
                    temp+=it->first;
                    it++;
                }

            }
            ans = min(ans,sum - temp);
        }
        printf("%d",ans);
        return 0;
    }
