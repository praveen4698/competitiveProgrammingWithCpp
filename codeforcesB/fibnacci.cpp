#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    ll A[101];
    int main()
    {
        A[0] = 1LL;
        A[1] = 2LL;
        int i=1;
        while(A[i] < 1e17)
        {
            i++;
            A[i] = A[i-2]+ A[i-1];
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            ll n;
            cin>>n;
            ll sum = 0LL;
            i=0;
            while(A[i]<n)
            {
                if( A[i]%2 == 0)
                    sum+=A[i];
                i++;
            }
            cout<<sum<<"\n";
        }
        return 0;
    }
