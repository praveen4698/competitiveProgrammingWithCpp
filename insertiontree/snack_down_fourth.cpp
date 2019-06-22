#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e5+10;
    long long int A[lim];
    long long int cost[lim];
    vector<long long int> B;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            B.clear();
            long long int n,k,a,b;
            scanf("%lld %lld %lld %lld",&n,&k,&a,&b);
            b = b-a;
            for(int i=0;i<n;++i)
            {
                long long int x;
                scanf("%lld",&x);
                A[i] = x-a;
            }
            sort(A,A+n);
            long long int ans = 0;
            for(int i=0;i<n;++i)
            {
                cost[i] = 1LL*i*k - A[i];
                if( cost[i] < 0)
                    B.push_back(-cost[i]);
                ans = ans + abs(cost[i]);
            }

            sort(B.begin(),B.end());
            int m = B.size();
            long long int posi = 1LL*(n-m);
            long long int negi = 1LL*m;
            long long int cont = 0;
            long long int range = 1LL*n*k;
           // printf("ans = %lld ",ans);
            for(int i=0;i<m;++i)
            {
               // printf("bb = %lld\n",B[i]);
             //   printf("posi = %lld negi = %lld\n",posi,negi);
               if(posi > negi)
                    break;
                long long int temp = B[i];
                temp = temp - cont;
                if( range+temp <= b)
                {
                    cont+=temp;
                    ans = -(1LL*negi*temp) + ans + (1LL*posi*temp);
                    posi++;
                    negi--;
                    range+=temp;
                }
                else if( range+temp > b )
                {
                    temp = b-range;
                    ans = -(1LL*negi*temp) + ans + (1LL*posi*temp);
                    break;
                }

            }
            printf("%lld\n",ans);
        }
        return 0;
    }
