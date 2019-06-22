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
    vector<ll> A;
    int n;
    scan(n);
    ll d;
    cin>>d;
    ll ans = 0;
    A.resize(n);
    for(int i=0;i<n;++i)
        cin>>A[i];
    sort(all(A));
    for(int i=0;i<n-2;++i)
    {
       // cout<<i<<endl;
        if( A[i+2] <= A[i]+d)
        {
            int a = lower_bound(all(A),A[i]+d) - A.begin();
            //cout<<a<<endl;
            if( A[i]+d == A[a])
            {
                ans = ans + (a-i)*1ll*(a-i-1)/2ll;
            }
            else
            {
                a--;
                ans = ans + (a-i)*1ll*(a-i-1)/2ll;

            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


