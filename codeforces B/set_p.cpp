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
set<pii> pi;
vi G[lim];
int P[lim];
int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n;
        S(n);
        pi.clear();
        for(int i=1;i<=n;++i)
        {
            G[i].clear();
            S(P[i]);
            pi.insert({P[i],i});
        }
        for(int i=0;i<n-1;++i)
        {
            int a,b;
            S2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;++i)
        {
            pi.erase({P[i],i});
            for(int a:G[i])
            {
                pi.erase({P[a],a});
            }
            if(pi.size() == 0)
                cout<<"0 ";
            else
            {
                int tt = (*pi.rbegin()).second;
                cout<<tt<<" ";
            }
            pi.insert({P[i],i});
            for(int a:G[i])
            {
                pi.insert({P[a],a});
            }
        }
        cout<<endl;
    }
   // int ss;
   // cin>>ss;
    return 0;
}


