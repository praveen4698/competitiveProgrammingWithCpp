#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vector<int> A;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,q;
            scanf("%d %d",&n,&q);
            A.clear();
            for(int i=0;i<n;++i)
            {
                int a;
                scanf("%d",&a);
                if( a != 1)
                    A.push_back(a);
            }
            while(q--)
            {
                int x;
                scanf("%d",&x);
                for(int a:A)
                {
                    x = x/a;
                    if( x == 0)
                        break;
                }
                printf("%d ",x);
            }
            printf("\n");
        }
        return 0;
    }
