#include<bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 10;
vector<int> G[lim];
int c[lim];

set<int> S[lim];
    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int ans = 1000001;
        for(int i=1;i<=n;++i)
         {
             scanf("%d",&c[i]);
             ans = min(ans,c[i]);
         }
        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for(int i=1;i<=n;++i)
        {

            for(int j:G[i])
            {
                if( c[i] != c[j])
                    S[c[i]].insert(c[j]);
            }

        }
        int maxi = 0;
        for(int i=1;i<=100000;++i)
        {
            if( S[i].size() > maxi)
            {
                maxi = S[i].size();
                ans = i;
            }

        }
        printf("%d",ans);


    }


