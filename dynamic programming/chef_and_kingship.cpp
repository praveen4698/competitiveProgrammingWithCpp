#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    vector<int> A(lim);
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            A.clear();
            A.resize(n);
            for(int i=0;i<n;++i)
                cin>>A[i];
            sort(A.begin(),A.end());
            long long int ans = 0;
            for(int i=1;i<n;++i)
                ans+=(A[i]*1LL*A[0]);
            printf("%lld\n",ans);
        }
        return 0;
    }
