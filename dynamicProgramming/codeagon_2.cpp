#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim =  2e5+10;
    long long int A[lim];

    int main()
    {
        long long int n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);
       // int ans = INF;
        long long int cont = 0;
        int temp = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%lld",&A[i]);
            if( A[i] == 1)
                temp++;
        }
        if( temp < m)
        {
            printf("-1");
            return 0;
        }
        if(m == 1)
        {
            for(int i=1;i<n;++i)
            {
                if( A[i] == 1)
                {
                    printf("%d",i);
                    return 0;
                }
            }
        }
        long long int cost = 0;
        long long int i=1;
        long long int one = 0;
         long long int pr ;
        vector<pair<long long int,long long int> > ans;
        for(int j=1;j<n;++j)
        {
            cost+=(1LL*cont);
            if( A[j] == 1)
            {
                one++;
                cont+=(1LL*k);
            }
            while(A[i] != 1 && i <= j)
                i++;
            if( one == m)
            {
                ans.push_back({i*1LL,cost});
                cont = (m-1)*1LL*k;
                 pr = i;

                i++;
                one--;
                while(A[i] != 1)
                {
                    i++;

                }
                int ss = j - pr;
                cost = cost - ss*1LL*k;
               // cost = cost + i-prev;
            }
        }
        long long int ret = INFL;
        for(int i=0;i<ans.size();++i)
        {
           // printf("%d\n",ans[i].first);
            ret = min(ret,1LL*ans[i].first+1LL*ans[i].second);
        }
        printf("%lld",ret);
        return 0;
    }
