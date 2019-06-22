#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6 + 10;
    int P[lim];
    vector<long long int> prime[1000001];
    int main()
    {
        long long int A,B;
        cin>>A>>B;
        for(long long int i = 2; i< lim;++i)
        {
            if(P[i] == 0)
            {
                P[i] = i;
                for(long long int j = 2*i;j<lim;j = i+j)
                    P[j] = i;
                for(long long int j = ((A+i-1)/i)*i;j<=B;j= j+i )
                    prime[j-A].push_back(i);
            }
        }
        printf("oipsij\n");
        long long int ans = 0;
        priority_queue<long long int> Q;
        for(long long int i = A;i<=B;++i)
        {
            long long int temp = 1,x = i;
            for(long long int j = 0;j<prime[i-A].size();++j)
            {
                long long int pr = prime[i-A][j],cont = 0;
                while(x%pr == 0)
                 {
                     cont++;
                     x = x/pr;
                 }
                temp*=(cont+1);
                Q.push(cont+1);

            }
            printf("oipsij\n");
            if(x>1)
            {
                temp*=2;
                Q.push(2);

            }
            ans+=temp-1;
            while(!Q.empty())
            {
                long long int t = Q.top();
                Q.pop();
                temp/=t;
                temp*=(t-1);
                ans+=temp;
                if(t>2)
                    Q.push(t-1);
            }

        }
        printf("%lld\n",ans);
        return 0;
    }
