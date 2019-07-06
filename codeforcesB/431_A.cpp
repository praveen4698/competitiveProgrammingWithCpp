#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 101;
    vector<vector<int> > ans;
    int A[lim];
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        int flag = 0;
        if(A[0]%2 == 0 || A[n-1]%2 == 0)
        {
            printf("No");
            return 0;
        }
        vector<int> t;
        for(int i=0;i<n;++i)
        {

                t.push_back(A[i]);
            if( i <n-1 && A[i+1]%2 == 1 && t.size()%2 == 1 && t[t.size()-1]%2 == 1)
            {
                ans.push_back(t);
                t.clear();
            }
            if( i == n-1 && t.size()%2 == 1)
            {
                ans.push_back(t);
                t.clear();
            }
            else if( i==n-1 && t.size()%2 == 0)
            {
                printf("Yes");
                return 0;
            }
        }
        if( ans.size()%2 == 1)
            printf("Yes");
        else
        {
            int flag = 0;
            for(int i=0;i<ans.size()-1;++i)
            {
                if( (ans[i].size()+ans[i+1].size())%2 == 1)
                    flag = 1;
            }
            if( flag == 1)
                printf("Yes");
            else
                printf("No");
        }

        return 0;
    }
