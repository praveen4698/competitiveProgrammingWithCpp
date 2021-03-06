#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

const int lim = 1e5+10;
ll A[lim],B[lim];
int main()
{
    int n,a,b;
    scan(n);
    cin>>a>>b;
    ll k = a+b;
    for(int i=0;i<n;++i)
        cin>>A[i];
    for(int i=0;i<n;++i)
        cin>>B[i];
    priority_queue<int> Q;
    for(int i=0;i<n;++i)
    {
        Q.push(abs(A[i]-B[i]));
    }
    while(k--)
    {
        ll t = Q.top();
       // cout<<t<<endl;
        Q.pop();
        t--;
        Q.push(abs(t));

    }
    ll ans = 0;
    while(!Q.empty())
    {
        ans = ans + 1ll*Q.top()*Q.top();
        Q.pop();
    }
    cout<<ans<<endl;
    return 0;
}


