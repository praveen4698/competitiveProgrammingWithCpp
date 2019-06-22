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
const ll mod = 1e9+7;
vector<int> num_to_digit(ll a)
{
    vector<int> ans;
    while(a)
    {
        ans.pb(a%10);
        a/=10;
    }
    reverse(all(ans));
    return ans;
}
int solve(vector<int> A)
{
    unordered_map<int,int> M;
    int ans = 0;
    for(int i=0;i<A.size();++i)
    {
        int val = 0;
        for(int j=i;j<A.size();++j){


            val^=A[j];
        if(M[val] == 0)
        {
            ans+=val;
            M[val] = 1;
        }}
    }
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int l,r;
        scan2(l,r);
        ll ans = 0;
        for(int i=l;i<=r;++i)
        {
            ans+=1ll*solve(num_to_digit(i));
            if( ans > mod)
                ans-=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}


