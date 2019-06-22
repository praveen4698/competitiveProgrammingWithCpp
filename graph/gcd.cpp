#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;

     long long int power(long long int c,long long int n)
    {
        if( c == 0)
            return 0;
        if( n == 0)
            return 1;
        if( c == 1)
            return 1;
        if( n == 1)
            return c;
        long long int temp = power(c,n/2);
        if( n%2 == 1)
            return (((temp*temp)%mod)*c)%mod;
        else
            return (temp*temp)%mod;
    }
    long long int A[10000001],b[10000001];

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,m,l,r;
            scanf("%d %d %d %d",&n,&m,&l,&r);
            long long int ans = 0;
            int prev = -1;
            for(int i = m;i > 0 ;--i)
            {
                if( prev == m/i)
                    A[i] = A[i+1];
                else
                {
                    A[i] = power(m/i,n);
                    prev = m/i;
                }
                int k =2*i;
                long long int temp = 0;
                while(k <= m)
                {
                    temp+=b[k];
                    k+=i;
                    if(temp > mod)temp = temp-mod;
                }
                b[i] = A[i] - temp;
                if( b[i] < 0) b[i]+=mod;
                if( b[i] > mod) b[i] = b[i]-mod;
                if( i >= l && i <= r)
                {
                    ans+=b[i];
                    if( ans > mod)ans= ans-mod;
                }
            }

            printf("%d\n",ans);

        }
        return 0;
    }
