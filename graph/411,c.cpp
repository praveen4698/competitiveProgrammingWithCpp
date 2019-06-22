#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[1000001];
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b%a, a);
    }
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;++i)
            scanf("%d",&A[i]);
        if(n == 1 && A[0] == 1)
        {
            printf("NO\n");
            return 0;

        }
        if( n == 1 && A[0] != 1)
        {
            printf("YES\n");
            printf("0\n");
            return 0;
        }
        int prev = 0;
        int HCF = A[0];
        int ans = 0;
        if(A[0]%2 == 1)
            prev = 1;
        for(int i = 1;i<n;++i)
        {
            HCF = gcd(HCF,A[i]);
            if( prev == 1)
            {
                if( A[i]%2 == 0)
                {
                    ans= ans +2;
                    prev = 0;
                }
                else
                {
                    ans = ans + 1;
                    prev = 0;
                }
            }
            else
            {
                if( A[i]%2 == 0)
                {

                    prev = 0;
                }
                else
                {

                    prev = 1;
                }
            }
        }
        if( prev == 1)
            ans = ans + 2;
        if(HCF > 1)
        {
            printf("YES\n");
            printf("0\n");

        }
        else
        {
            printf("YES\n");

            printf("%d\n",ans);
        }
        return 0;
    }
