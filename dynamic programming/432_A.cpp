#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int n,k,t;
        scanf("%d %d %d",&n,&k,&t);
        if( t <= k)
            printf("%d\n",t);
        else if( t > k && t <= n)
            printf("%d\n",k);
        else
            printf("%d\n",n+k-t);
        return 0;
    }
