#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;


int main()
{
    double k,d,t;
    cin>>k>>d>>t;
    d = (double)(floor((k+d-1)/d))*d;
    double temp = k + 0.5*(d-k);
   // cout<<temp<<endl;
    double ans = (double)(floor(t/temp)*1.00*d);
   // cout<<ans<<endl;
    double temp2 = t - (double)(floor(t/temp)*1.00*temp);
    if( temp2 <= k)
        ans+=temp2;
    else
    {
        ans+=k;
        ans+=((temp2-k)*2.00);
    }
    printf("%.15f\n",ans);
    return 0;
}


