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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1010;
int A[lim];
pair<double,double> B[lim];
int main()
{
    for(int i=0;i<lim;++i)
    {
        B[i].fi = 0.00;
        B[i].se = 0.00;
    }
    int n;
    int r;

    S(n);
    cin>>r;
    for(int i=0;i<n;++i)
        S(A[i]);
    for(int i=0;i<n;++i)
    {
        double xx = 4.00*r*r;
        double yy = (B[A[i]].fi - A[i])*(B[A[i]].fi - A[i]);
        cout<<xx<<endl<<yy<<endl;
        double ans = sqrt(4.00*r*r - (1.00*B[A[i]].fi-1.00*A[i])*(1.00*B[A[i]].fi-1.00*A[i]));
        cout<<ans<<endl;
        int lo = max(A[i] - r,0);
        int hi = min(A[i] + r,lim);
        double offset = B[A[i]].se;
        for(int j=lo;j<=hi;++j)
        {
            B[j].fi = A[i]*1.00;
            B[j].se = ans + offset;
        }
        ans+=offset;
        printf("%.10f ",ans);
    }
    return 0;
}
