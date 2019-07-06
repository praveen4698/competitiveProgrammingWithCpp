#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e4+10;
    int A[lim];
    map<int,int> M;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            M.clear();
            int flag = 0;
            int flag2 = 1;
            for(int i=0;i<n;++i)
            {
                scanf("%d",&A[i]);
                M[A[i]]++;
                if( M[A[i]] >= 2 || A[i] > n)
                    flag = 1;
                if( i > 0 && A[i] < A[i-1])
                    flag2 = 0;
            }
            if( flag2 == 0 && flag == 0)
                printf("Beautiful\n");
            else
                printf("Ugly\n");
        }
        return 0;
    }
