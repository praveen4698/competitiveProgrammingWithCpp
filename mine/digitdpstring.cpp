#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                    29, 31, 37, 41, 43, 47, 53, 59,
                    61, 67, 71, 73, 79, 83, 89, 97,
                    101, 103, 107, 109};
    bool vis[50][50][50][50];
    int dp[50][50][50][50];
    int isPrime(long long int x)
    {
        if(x<0)
            return 0;
        for(int i=0;i<29;i++)
            if(prms[i]==x)
                return 1;
        return 0;
    }
    long long int F(int dig,long long int three,long long int six,int nine)
    {
        if(dig==0)
         {
             if( three == six && six == nine && three >= 1)
                return 1;
             else
                return 0;
         }

        if(vis[dig][three][six][nine] ==true)
            return dp[dig][three][six][nine];
        vis[dig][three][six][nine] = true;
        long long int ans = 0LL;
        for(int i=0;i<10;++i)
        {
            if( i == 3)
                ans = ans + F(dig-1,three+1,six,nine);
            else if(i == 6)
                ans = ans + F(dig-1,three,six+1,nine);
            else if( i == 9)
                ans = ans + F(dig-1,three,six,nine+1);
            else
                ans = ans + F(dig-1,three,six,nine);

            ans = ans%mod;
        }
        dp[dig][three][six][nine] = ans;
        return ans;


    }
    long long int solve(vector<int> &A)
    {

        long long int ans =0,three=0,six=0,nine=0;
        int n = A.size();
        int j = n;
        for(int i=0;i<n;++i)
        {
            int d = A[i];
            //printf("%d",d);
            j--;
            for(int k=0;k<d;++k)
            {
                if( k == 3)
                    ans = ans + F(j,three+1,six,nine);
                else if(k == 6)
                    ans = ans + F(j,three,six+1,nine);
                else if( k == 9)
                    ans = ans + F(j,three,six,nine+1);
                else
                     ans = ans +  F(j,three,six,nine);

                ans= ans%mod;
            }
            if( d == 3)
                three++;
            else if(d == 6)
                six++;
            else if( d == 9)
                nine++;


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
            string a,b;
            cin>>a>>b;
            vector<int> A;
            for(int i =0;i<a.size();++i)
                A.push_back(a[i]-'0');
            vector<int> B;
            for(int i =0;i<b.size();++i)
                B.push_back(b[i]-'0');
            int carry = 1;
            for(int i=B.size()-1;i>=0;--i)
            {
                B[i] = (B[i]+carry);
                carry = B[i]/10;
                B[i] = B[i]%10;
            }
            if(carry == 1)
            {
                reverse(B.begin(),B.end());
                B.push_back(1);
                reverse(B.begin(),B.end());
            }
            long long int ans = solve(B)-solve(A);
            if( ans < 0)
                ans = ans + mod;
            ans = ans%mod;
            printf("%lld\n",ans);
        }
        return 0;
    }
