#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
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
const int lim = 1e5+10;
int C[lim],R[lim];
pii query[lim];


int main()
{
    memset(C,0,sizeof(C));
    memset(R,0,sizeof(R));
    int n;
    S(n);
    ll sum = 0;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        S2(a,b);
        R[i] = b-a+1;
        C[a]++;
        C[b+1]--;
        sum+=(1ll*R[i]);
        query[i].fi = a;
        query[i].se = b;
    }
    for(int i =1;i<=n;++i)
        C[i]+=C[i-1];
    int q;
    S(q);
    while(q--)
    {
        int a,b;
        S2(a,b);
        ll temp = sum - 1ll*R[a] - 1ll*C[b];
        if( b <= query[a].se && b >= query[a].fi)
            temp--;
        if( temp%2 == 1)
            cout<<"O";
        else
            cout<<"E";
        cout<<endl;
    }

    return 0;
}


