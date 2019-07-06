#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                    29, 31, 37, 41, 43, 47, 53, 59,
                    61, 67, 71, 73, 79, 83, 89, 97,
                    101, 103, 107, 109};
    bool vis[25][300][300];
    long long int dp[25][300][300];
    long long int K;
    int isPrime(long long int x)
    {
        if(x<0)
            return 0;
        for(int i=0;i<29;i++)
            if(prms[i]==x)
                return 1;
        return 0;
    }
    long long int F(int dig,long long int mod,long long int sum)
    {
        if(dig==0)
        {
            if( mod%K == 0 && sum%K == 0)
                return 1;
            else
                return 0;
        }
        if(vis[dig][mod][sum] ==true)
            return dp[dig][mod][sum];
        vis[dig][mod][sum] = true;
        long long int ans = 0LL;
        for(int i=0;i<10;++i)
        {

                ans+=F(dig-1,(mod*10+i)%K,sum+i);

        }
        dp[dig][mod][sum] = ans;
        return ans;


    }
    long long int solve(long long int a)
    {
        vector<int> A;
        while (a)
        {
            A.push_back(a % 10);
            a /= 10;
        }
        reverse(A.begin(),A.end());
        long long int ans =0;
        int n = A.size();
        int j = n;
        long long int  mod = 0;
        long long int sum = 0;
        for(int i=0;i<n;++i)
        {
            int d = A[i];
            //printf("%d",d);
            j--;
            for(int k=0;k<d;++k)
            {

                    ans+=F(j,(mod*10 + k)%K,sum+k);

            }
            sum = sum+d;
            mod = (mod*10+d)%K;

        }
        return ans;
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        memset(vis,false,sizeof(vis));
        int x = 1;
        while(t--)
        {
            long long int a,b;
            cin>>a>>b>>K;
            memset(vis,false,sizeof(vis));
            if(K >= 300)
                printf("Case %d: 0\n",x);
            else
                printf("Case %d: %lld\n",x,solve(b+1)-solve(a));

            x++;
        }
        return 0;
    }

