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
vector<int> G[lim];
int A[lim],B[lim];

int main()
{
    int n,m;
    scan2(n,m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scan2(a,b);
        G[a].pb(b);
        G[b].pb(a);
    }
    memset(B,0,sizeof(B));
    vector<int> ans;
    queue<int> Q;
    for(int i=1;i<=n;++i)
    {
        scan(A[i]);
        if( A[i] == B[i])
            Q.push(i);
    }
    cout<<"sdz"<<endl;
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        ans.pb(x);
        for(int a:G[x])
        {
            B[a]++;
            if( B[a] == A[a])
                Q.push(a);
        }
    }
    cout<<ans.size()<<endl;
    for(int a:ans)
        cout<<a<<" ";

    return 0;
}


