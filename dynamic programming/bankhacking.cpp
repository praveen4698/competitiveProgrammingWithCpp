#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 3e5+5;
    int w[lim];
    bool isin[lim],rem[lim];
    vector<int> T[lim];
    struct comp {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
            {return lhs.second<rhs.second;}
        };
    multiset<pair<int,int>,comp> M;
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&w[i]);
            isin[i] =false;
            rem[i] = false;
        }
        for(int i=0;i<n-1;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            T[a].push_back(b);
            T[b].push_back(a);
        }
        int maxi = -INF;
        int ind ;
        for(int i=1;i<n+1;++i)
        {
            if( maxi < w[i])
            {
                maxi = w[i];
                ind = 1;
            }
        }
        isin[ind] = true;
        M.insert(make_pair(ind,w[ind]))
        multiset
        return 0;
    }
