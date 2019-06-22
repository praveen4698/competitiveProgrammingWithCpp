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
    int ans = 0;
    int a,b;
    a = 0;
    cin>>b;
    while( b>a)
    {
        ans+=(b-a);
        b--;
        a++;
    }
    cout<<ans<<endl;
    return 0;
}
