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
vector<int> A[lim];
vector<pair<int,int> > ans;
int deg[lim];
int main()
{
    int n,k;
    memset(deg,0,sizeof(deg));
    scan2(n,k);
    int maxi = -1;
    for(int i=1;i<=n;++i)
    {
        int a;
        scan(a);
        A[a].pb(i);
        maxi = max(a,maxi);
    }
    int flag = 0;
    if( A[0].size() > 1)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<maxi;++i)
    {
        if( A[i].size() == 0)
        {
            flag = 1;
            break;
        }
        int j = 0 ;
        int t = 0;
        while(j < A[i+1].size())
        {
            if( deg[A[i][t]] < k)
            {
                ans.pb({A[i][t],A[i+1][j]});
                deg[A[i][t]]++;
                deg[A[i+1][j]]++;
                j++;
            }
            else
            {
                t++;
                if( t == A[i].size())
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if( flag == 1)
        printf("-1\n");
    else
    {
        cout<<ans.size()<<endl;
        for(auto i:ans)
            cout<<i.fi<<" "<<i.se<<endl;
    }
    return 0;
}


