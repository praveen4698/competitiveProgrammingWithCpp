#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;


int main()
{
    int t;
    S(t);
    while(t--)
    {
        ll A,N;
        scanf("%lld %lld",&A,&N);
        while(A > 9)
        {
            ll temp = A;
            A = 0;
            while(temp > 0)
            {
                ll tt = (temp)%10;
                A = A + tt;
                temp = temp/10;
            }
            //cout<<A<<endl;
        }
        while(N > 9)
        {
            ll temp = N;
            N = 0;
            while(temp > 0)
            {
                ll tt = (temp)%10;
                N = N+ tt;
                temp = temp/10;
            }
        }
        ll ans = 1;
        for(int i=0;i<N;++i)
            ans = ans*A;
        while(ans > 9)
        {
            ll temp = ans;
            ans = 0;
            while(temp > 0)
            {
                ll tt = (temp)%10;
                ans = ans + tt;
                temp = (temp)/10;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}


