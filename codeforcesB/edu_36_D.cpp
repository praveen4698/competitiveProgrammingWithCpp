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

int A[10],D[10];
vi B,C;
ll solve(int x)
{
    int A1[10];
    int flag = 0;
    vi ans;
    for(int i=0;i<10;++i)
        A1[i] = A[i];
    for(int i=0;i<B.size();++i)
    {
        if( flag == 0 && i == x)
        {
            int x = B[i]-1;
            while(x >= 0)
            {
                if( A1[x] > 0)
                {
                    A1[x]--;
                    ans.pb(x);
                    if( x < B[i])
                        flag = 1;
                    x = -1;
                }
                x--;
            }
        }
        else if( flag == 0)
        {
            int x = B[i];
            while( x >= 0)
            {
                if( A1[x] > 0)
                {
                    ans.pb(x);
                    A1[x]--;
                    if( x < B[i])
                        flag = 1;
                   // break;
                    x = -1;
                }
                x--;

            }
        }
        else
        {
            int x = 9;
            while(x>=0)
            {
                if( A1[x] > 0)
                {
                    ans.pb(x);
                    A1[x]--;
                   // break;
                    x = -1;
                }
                x--;
            }
        }

    }
    ll temp = 0ll;
    for(int a:ans)
        temp = temp*1ll*10 + a*1ll;
    return temp;
}
int main()
{
    memset(A,0,sizeof(A));
    memset(D,0,sizeof(B));
    //memset(B,0,sizeof(B));
    ll a;
    cin>>a;
    ll b;
    cin>>b;

    while(a > 0)
    {
        A[a%10]++;
        D[a%10]++;
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
   // vi ans,ans2;
    int flag = 0;
    ll ans = 0ll;
    for(int i=0;i<B.size()+1;++i)
    {
        ans = max(ans,solve(i));
    }
    cout<<ans<<endl;
    return 0;
}
