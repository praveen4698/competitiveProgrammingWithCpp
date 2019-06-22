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
const int lim = 1e5+10;
int A[lim];
int main()
{
    int n;
    S(n);
    for(int i=0;i<n;++i)
        S(A[i]);
    int prev = -1;
    int mini  = INF;
    for(int i=0;i<n;++i)
        mini = min(A[i],mini);
    int ans = INF;
    for(int i=0;i<n;++i)
    {
        if( A[i] == mini)
        {
            if( prev != -1)
                ans = min(ans,i-prev);
            prev =i;
        }

    }
    cout<<ans<<endl;
    return 0;
}
