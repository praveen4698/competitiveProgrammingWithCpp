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
vector<int> X,Y;

int main()
{
    int n,m;
    scan2(n,m);
    ll cost = 0ll;
    for(int i=0;i<n;++i)
    {
        int a,b;
        scan2(a,b);
        X.pb(a);
        Y.pb(b);
        cost = cost + 1ll*(abs(a)+abs(b));
    }
    sort(all(X));
    sort(all(Y));
    int x = 0;
    int y = 0;
    string S;
    cin>>S;
    for(int i=0;i<m;++i)
    {
        if( S[i] == 'R')
        {
            int a = upper_bound(all(X),x) - X.begin();
            cost = cost + 1ll*a;
            cost = cost - 1ll*(n-a);
            x++;
        }
        if( S[i] == 'L')
        {
            int a = lower_bound(all(X),x)-X.begin();
            cost = cost + 1ll*(n-a);
            cost = cost - 1ll*a;
            x--;
        }
        if( S[i] == 'U')
        {
            int a = upper_bound(all(Y),y)- Y.begin();
            cost = cost + 1ll*a;
            cost = cost - 1ll*(n-a);
            y++;
        }
        if( S[i] == 'D')
        {
            int a = lower_bound(all(Y),y)-Y.begin();
            cost = cost + 1ll*(n-a);
            cost = cost - 1ll*a;
            y--;
        }
        cout<<cost<<endl;


    }

    return 0;
}


