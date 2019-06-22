#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 510;
    long long int G[lim][lim];
    long long int A[lim];
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cin>>G[i][j];
            }
        }
        for(int i=1;i<=n;++i)
            cin>>A[i];

        reverse(A+1,A+n+1);
        stack<long long int> ans;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                for(int k=1;k<=n;++k)
                {
                    G[A[j]][A[k]] = min(G[A[j]][A[k]],G[A[j]][A[i]] + G[A[i]][A[k]]);
                }
            }
            long long int temp = 0;
            for(int j = 1;j<=i;++j)
            {
                for(int k=1;k<=i;++k)
                {
                    temp+=G[A[j]][A[k]];
                }
            }
            ans.push(temp);
        }
        while(!ans.empty())
        {
            cout<<ans.top()<<" " ;
            ans.pop();
        }
        return 0;
    }

