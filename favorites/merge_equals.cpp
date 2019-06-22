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
const int lim = 1e6;
map<ll,set<ll> > M;
int A[lim],B[lim];
vector<ll> ans;

int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        scan(A[i]);
        M[1ll*A[i]].insert(1ll*i);
    }
    memset(B,0,sizeof(B));
    for(auto m:M)
    {
        ll a = m.first;
        while( m.second.size() >= 2)
        {
            m.second.erase(m.second.begin());
            M[2*1ll*a].insert(*m.second.begin());
            m.second.erase(m.second.begin());
        }
       // cout<<a<<endl;
        if( a < -1)
        {
            cout<<"mlmlmlm-1"<<endl;
            return 0;
        }
        for(auto s:m.second )
        {
            B[s] = a;
            if( a < 0 || s >= n )
            {
                cout<<"ufu-1"<<endl;
                return 0;
            }
        }
    }
   // for(int i=0;i)
    for(int i=0;i<n;++i)
    {
        if( B[i] < 0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        if( B[i]  != 0)
            ans.push_back(B[i]);
    }
    cout<<ans.size()<<endl;
    for(ll a:ans)
        cout<<a<<" ";

    return 0;
}


