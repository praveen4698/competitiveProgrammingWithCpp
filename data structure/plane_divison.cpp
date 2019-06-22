#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int gcd(int a,int b)
    {

    }
    map<pair<int,int> , set<int> > M;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            M.clear();
            for(int i=0;i<n;++i)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                int gd = __gcd(a,b);
                gd  = __gcd(gd,c);
                cout<<gd<<"\n";
                a = a/gd;
                b = b /gd;
                c = c/gd;
                M[make_pair(a,b)].insert(c);
            }
            int ans = 1;
            for(auto m:M)
            {
                set<int> temp = m.second;
                int ss = temp.size();
                ans = max(ans,ss);
            }
            printf("%d\n",ans);
        }
        return 0;
    }
