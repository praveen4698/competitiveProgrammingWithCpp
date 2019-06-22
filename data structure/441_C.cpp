#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int n;
        scanf("%d",&n);
        vector<int> ans;
        int mini = max(0,n-90);
        for(int i=n;i>= mini;--i)
        {
            int sum = 0;
            int j = i;
            while(j>0)
            {
                sum = sum + j%10;
                j = j/10;
            }
            if( sum+i == n)
                ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(int i:ans)
        {
            printf("%d\n",i);
        }
        return 0;
    }

