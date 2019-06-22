#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 2e5+10;
    int A[lim],B[lim];

    vector<vector<int> > ans;
    int solve(int n)
    {
        vector<int> ans1;
       // int n;
       // scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
                scanf("%d",&A[i]);
        }
        for(int i=0;i<n;++i)
            scanf("%d",&B[i]);
        for(int i=0;i<n;++i)
        {
            ans1.push_back(max(A[i],B[i]));
        }
        sort(ans1.begin(),ans1.end());
        reverse(ans1.begin(),ans1.end());
        for(int i=0;i<n;++i)
        {
            printf("%d ",ans1[i]);
        }
        return 0;
    }
    int main()
    {
        int n;
        scanf("%d",&n);
        if(n > 10000)
        {
            int x = solve(n);
            return 0;
        }
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        for(int i=0;i<n;++i)
            scanf("%d",&B[i]);
        for(int i=0;i<n;++i)
        {
            vector<int> t;
            ans.push_back(t);
            for(int j=0;j<n;++j)
            {
                if( j<i)
                    ans[i].push_back(A[j]);
                else
                    ans[i].push_back(B[j]);
            }
            sort(ans[i].begin(),ans[i].end());
            reverse(ans[i].begin(),ans[i].end());
           /* for(int j=0;j<n;++j)
                printf("%d ",ans[i][j]);
            printf("\n"); */
        }
        vector<int> tt;
        ans.push_back(tt);
        for(int i=0;i<n;++i)
        {
            ans[ans.size()-1].push_back(A[i]);
        }
        sort(ans[n].begin(),ans[n].end());
        reverse(ans[n].begin(),ans[n].end());
        vector<int> ret;
        for(int i=0;i<n;++i)
            {
                int maxi = -1;
                for(int j=0;j<ans.size();++j)
                    maxi = max(ans[j][i],maxi);
                ret.push_back(maxi);
            }
        for(int i=0;i<n;++i)
            printf("%d ",ret[i]);
        return 0;
    }
