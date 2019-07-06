#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    long long int h,w,f,R[30],n;
    long long int solve(long long int e,long long int i)
    {
        long long int cost = 0;
        if(e > R[i])
            cost = e*w;
        else
         {
             cost = (R[i]-e )*h + R[i]*w;
             e = R[i];
         }

        if( i+1 >= n)
            return cost;
        else
        {
            long long int temp = INFL;
            if( e > R[i+1])
                temp = f*(e-R[i+1]) + solve(R[i+1],i+1);
           // if(i == 0)
              //  printf("cost = %lld temp = %lld\n",cost,temp);
            return (cost + min(solve(e,i+1),temp));
        }
    }
    int main()
    {
        scanf("%lld",&n);
        int x = 1;
        while(n != 0)
        {
            scanf("%lld %lld %lld",&h,&w,&f);
            for(int i=0;i<n;++i)
                scanf("%lld",&R[i]);
            printf("Case %d, cost = $%lld\n",x,solve(0,0));
            scanf("%lld",&n);
            x++;
        }
        return 0;
    }
