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
unordered_map<ll,int> M;
int main()
{
    ll mod = pow(2,32);
   // cout<<mod<<endl;
    ll q;
    unsigned int s,a,b;
    scanf("%lld %u %u %u",&q,&s,&a,&b);
    ll sum = 0;
    for(int i=0;i<q;++i)
    {
       // cout<<s<<endl;
        if( s%2 == 1)
        {
            if( M.find(s/2) == M.end())
            {
                M.insert(make_pair(s/2,1));
                sum+=(1ll*s/2);
            }
        }
        else
        {
            if(M.find(s/2) != M.end())
            {
                M.erase(s/2);
                sum-=(1ll*s/2);
            }
        }
        //printf("%lld ",sum);
        s = a*s + b;
       // s%=mo;
    }
    printf("%lld",sum);
    return 0;
}
