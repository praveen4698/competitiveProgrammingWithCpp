#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            string S;
            int n,k;
            scanf("%d %d",&n,&k);
            cin>>S;
            priority_queue<int> Q;
            int cont = 1;
            for(int i=1;i<n;++i)
            {
                if(S[i] == S[i-1])
                {
                    cont++;
                    continue;
                }
                if( S[i] != S[i-1])
                {
                    Q.push(cont);
                    cont = 1;

                }
            }
            Q.push(cont);
            while(k--)
            {
                int t = Q.top();
                Q.pop();
                if(t == 1)
                    Q.push(1);

                int r = t/2;
                if( t%2 == 1)
                {
                    Q.push(r);
                    Q.push(r);
                    Q.push(1);
                }
                else
                {
                    Q.push(r);
                    Q.push(r-1);
                    Q.push(1);
                }
            }
            int ans = Q.top();
            printf("%d\n",ans);
        }

        return 0;
    }
