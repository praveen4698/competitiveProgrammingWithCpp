#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[501];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,p;
           // int A[3];
            cin>>n>>p;
            for(int i=0;i<n;++i)
            {
                cin>>A[i];
            }
            sort(A,A+n);
            if( n <3)
            {
                printf("no\n");
                continue;
            }
            if( A[n-1] >= p/2 && A[0] <= p/10 && A[1] <= p/10 && A[2] > p/10 && A[n-2] < p/2  )
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        return 0;
    }

