#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[70];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            unsigned long long int n,k;
            cin>>n>>k;
            for(int i=0;i<n;++i)
                A[i] = 0;
            unsigned long long int x = 1;
            for(long long int i=0;i<n;++i)
            {

                if( k&(x))
                    A[i] = 1;
                x = 2LL*x;
            }
            unsigned long long int r = 1;
            unsigned long long int ans = 0;
            for(int i=n-1;i>=0;--i)
            {
                if(A[i] == 1)
                    ans+=(r);
                r = 2LL*r;
            }
            cout<<ans;
            printf("\n");
        }
        return 0;
    }
