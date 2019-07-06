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

int A[10];
vi B,C;
int main()
{
    memset(A,0,sizeof(A));
    //memset(B,0,sizeof(B));
    ll a;
    cin>>a;
    ll b;
    cin>>b;
    ll t = b;
    while(a > 0ll)
    {
        A[a%10]++;
        C.pb(a%10);
        a= a/10;
    }
    while(b>0)
    {
        B.pb(b%10);
        b = b/10;
    }
    if( C.size() < B.size())
    {
        sort(all(C));
        reverse(all(C));
        for(int c:C)
            cout<<c;
        return 0;
    }
    reverse(all(B));
   // vi ans;
    int flag = 0;
    ll ans = 0ll;
    for(int i=0;i<1000000;++i)
    {
        random_shuffle(all(C));
        ll temp = 0ll;
        if( C[0] ==0)
            continue;
        for(int x:C )
            temp = temp*1ll*10 + x*1ll;
        if( temp <= t)
            ans = max(ans,temp);

    }
//    for(int aa:ans)
    //    cout<<aa;
    cout<<ans;
    return 0;
}


