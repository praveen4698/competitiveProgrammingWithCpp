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
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
int cont[lim];
map<pair<int,int> ,int > M;
int A[lim];
vector<pair<int,pair<int,int> > > query;
vector<int> G[lim];
vector<int> factors[lim];
int main()
{
    int n,q;
    scan2(n,q);
    for(int i=1;i<lim;++i)
    {
        for(int j=i;j<lim;j+=i)
        {
            factors[j].pb(i);
        }
    }
    for(int i=1;i<=n;++i)
        scan(A[i]);
    for(int i=0;i<q;++i)
    {
        int l,r,k;
        scan3(l,r,k);
        query.pb({l,{r,k}});
        G[l-1].pb(k);
        G[r].pb(k);
    }
    memset(cont,0,sizeof(cont));
    for(int i=1;i<=n;++i)
    {
        for(int j:factors[A[i]])
            cont[j]++;
        for(int j:G[i])
        {
            M[{i,j}] = cont[j];
        }
    }
    for(int i=0;i<q;++i)
    {
        int l = query[i].fi;
        int r = query[i].se.fi;
        int k = query[i].se.se;
        int ans = M[{r,k}] - M[{l-1,k}];
        printf("%d\n",ans);
    }
    return 0;
}


