#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    long long int A[lim];
    long long int W[lim];

    int main()
    {
        int t;
        scanf("%d",&t);
        map<long long int,int> M;
        while(t--)
        {
            int n;
            scanf("%d",&n);
            M.clear();
            for(int i=0;i<n;++i)
                scanf("%lld",&A[i]);
            for(int i=0;i<n;++i)
                scanf("%lld",&W[i]);
            long long int ans = -1;
            long long int temp = 0;
            int j= 0;
            for(int i=0;i<n;++i)
            {
                M[A[i]]++;
                while(M[A[i]] > 1)
                {
                    temp-=W[j];
                    M[A[j]]--;
                    j++;

                }
                temp+=W[i];
                if(temp>ans)
                    ans = temp;
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
