#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                    29, 31, 37, 41, 43, 47, 53, 59,
                    61, 67, 71, 73, 79, 83, 89, 97,
                    101, 103, 107, 109};
    bool vis[10][100][100];
    int dp[10][100][100];
    int isPrime(long long int x)
    {
        if(x<0)
            return 0;
        for(int i=0;i<29;i++)
            if(prms[i]==x)
                return 1;
        return 0;
    }
    long long int F(int dig,long long int odd,long long int even,int turn)
    {
        if(dig==0)
            return( 1LL*(isPrime(even-odd)));
        if(vis[dig][odd][even] ==true)
            return dp[dig][odd][even];
        vis[dig][odd][even] = true;
        long long int ans = 0LL;
        for(int i=0;i<10;++i)
        {
            if(turn ==1)
                ans+=F(dig-1,odd,even+i,1-turn);
            else
                ans+=F(dig-1,odd+i,even,1-turn);
        }
        dp[dig][odd][even] = ans;
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
        long long int ans =0,even=0,odd=0;
        int n = A.size();
        int j = n;
        for(int i=0;i<n;++i)
        {
            int d = A[i];
            //printf("%d",d);
            j--;
            for(int k=0;k<d;++k)
            {
                if((n-i)&1)
                    ans+=F(j,odd+k,even,1);
                else
                    ans+=F(j,odd,even+k,0);
            }
            if((n-i)&1)
                odd+=d;
            else
                even+=d;

        }
        return ans;
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        memset(vis,false,sizeof(vis));
        while(t--)
        {
            long long int a,b;
            cin>>a>>b;
            printf("%lld\n",solve(b+1)-solve(a));
        }
        return 0;
    }
