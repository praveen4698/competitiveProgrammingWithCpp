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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

struct comp {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
            {return lhs.second<rhs.second;}
        };
int main()
{
    vector<pair<int,int> > A;
    multiset<int> S;
    int n,k;
    scan2(n,k);
    for(int i=0;i<n;++i)
    {
        int a,b;
        scan2(a,b);
        A.push_back({a,b});
        S.insert(a);
    }
    ll ans = INFL;
    sort(all(A),comp());
    ll   sum = 0ll;
    reverse(all(A));
    ll x = 1ll;
    for(auto a:A)
    {
       // cout<<"AS"<<endl;
      // cout<<a.second<<" "<<(*S.rbegin())<<endl;
        ll temp = 1ll*k - 1ll*sum - 1ll*a.second;
       // cout<<"-"<<endl;
        ll cost = INFL;
        if( temp > 0ll)
            cost = (1ll*temp)/(1ll*(*S.rbegin())) + 1ll*x;
        else
            cost = 1ll*x;
        x++;
        if( temp > 0ll && (1ll*temp)%(1ll*(*S.rbegin())) != 0)
           cost++;
       // cout<<temp<<" "<<cost<<endl;
        ans = min(cost,ans);
        S.erase(S.find(a.first));
        sum+=(1ll*a.second);
    }
    cout<<ans<<endl;
    return 0;
}


