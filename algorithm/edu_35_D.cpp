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
const int lim = 2001;
int A[lim];
int main()
{
    int n;
    S(n);
    for(int i=0;i<n;++i)
        S(A[i]);
    ll total = 0ll;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if( A[i] > A[j])
                total = total + 1ll;
        }
    }
    int q;
    S(q);
    while(q--)
    {
        int a,b;
        S2(a,b);
        total = total + ((b-a+1)*1ll*(b-a))/2ll ;
        if( total%2 == 1ll)
            printf("odd\n");
        else
            printf("even\n");
    }
    return 0;
}
