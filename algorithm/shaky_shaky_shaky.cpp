#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
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
int A[lim];
int n,k;
bool solve(int x)
{
    int cont = 0;
    for(int i=0;i<n;++i)
    {
        cont+=(A[i]/x);
    }
    return (cont>=k);
}

int main()
{
    vector<ll> A;
    ll prev = 0;
    int q;
    int n;
    scan2(n,q);
    for(int i=0;i<n;++i)
    {
        ll a,b;
        cin>>a>>b;
        prev = prev + a*1ll*b;
        A.pb(prev);
    }
  //  int q;
  //  scan(q);
    while(q--)
    {
        ll a;
        cin>>a;
        int ans = lower_bound(all(A),a)-A.begin();
        ans++;
        cout<<ans<<endl;
    }
    return 0;
}
