#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                printf("%d",2*i+1);
                if(i == n-1)
                    printf("\n");
                else
                    printf(" ");
            }
        }
        return 0;
    }
