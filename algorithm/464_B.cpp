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

const int lim = 1e5;
ll A[lim];
int main()
{
    fast
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<k;++i)
        cin>>A[i];
    ll ans = 0;
    ll rem = n%A[0];
    ll quot = n/A[0];
    for(int i=1;i<k;++i)
    {
        ll temp = n%A[i];
        if(temp < rem)
        {
            rem = temp;
            ans = i;
            quot = n/A[i];
        }
    }
    cout<<ans+1<<" "<<quot<<endl;
    return 0;
}


