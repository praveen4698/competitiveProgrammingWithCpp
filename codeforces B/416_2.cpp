#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[10001];
    int main()
    {
        int n,m;
        int a,b,c;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%d",&A[i]);
        while(m--)
        {

            scanf("%d %d %d",&a,&b,&c);
            int cont = 0;
            for(int i = a;i <= b;++i)
            {
                if( cont > c-a)
                    break;
                if( A[i] < A[c])
                    cont++;
            }
            if( cont == (c-a))
                printf("Yes\n");
            else
                printf("No\n");
        }
        return 0;
    }
