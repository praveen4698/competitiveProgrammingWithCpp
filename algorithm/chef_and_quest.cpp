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


int main()
{
    int t;
    S(t);
    while(t--)
    {
        int a,b;
        S2(a,b);
        cout<<((a)*1ll*(a-1)/2ll)*(((b)*1ll*(b-1))/2ll)<<endl;
    }
    return 0;
}
