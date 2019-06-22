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
const int lim = 1e6+10;
ll A[lim];
vector<int> ans;

int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n;
        scan(n);
        ll sum = 0;
        ans.clear();
        for(int i=0;i<n;++i)
        {
            cin>>A[i];
            sum+=A[i];
        }
        ans.pb(1);
        for(int i=2;i<=n;++i)
        {
            ll cont = 0;
            ll ans1 = 0;
            if( sum%i > 0)
            {
                ans.pb(0);
                continue;
            }
            else
            {
                ll temp = 1ll*sum/i;
                for(int j=0;j<n;++j)
                {
                    cont+=A[j];
                    if(cont > temp)
                        break;
                    else if( cont == temp)
                        ans1++,cont = 0;

                }
            }
            if( ans1 == i)
                ans.pb(1);
            else
                ans.pb(0);
        }
        for(auto a:ans)
            cout<<a;
        cout<<endl;
    }
    return 0;
}


