#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int a,b,n;
    S3(n,a,b);
    int ans = -INF;
    for(int i=1;i<n;++i)
    {
        if( i <= a && n-i <=b)
            ans = max(ans,min(a/i,b/(n-i)));
    }
    cout<<ans<<endl;
    return 0;
}
