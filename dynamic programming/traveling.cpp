#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e4;
    map<string,int> M,sec;

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            string A[lim],B[lim];
            string cost[lim];
            M.clear();
            sec.clear();
            int n;
            scanf("%d",&n);
            int ans = 0;
            for(int i=1;i<n;++i)
            {
                cin>>A[i]>>B[i]>>cost[i];
                int t = 0;
                for(int j=0;j<cost[i].size()-1;++j)
                {
                    t = t*10 + (int)(cost[i][j] - '0');
                }
                ans+=t;
                M[A[i]] = i;
                sec[B[i]] = i;
            }
            int start = -1;
            for(int i=1;i<n;++i)
            {
                if(sec[A[i]] == 0)
                {
                    start = i;
                    break;
                }
            }
            int i=0;
            while(i<n-1)
            {
               // printf("%d\n",start);
                cout<<A[start]<<" "<<B[start]<<" "<<cost[start]<<endl;
                i++;
                start = M[B[start]];
            }
            printf("%d$\n",ans);
        }
        return 0;
    }
