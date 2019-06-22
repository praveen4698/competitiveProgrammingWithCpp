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
const int lim = 501;
int taken[lim],M[lim][lim];
ll costi[lim];
int n,m;
ll ans ;
void solve(int k,ll cost)
{
    int flag = 0;
    for(int i=0;i<n;++i)
        if( taken[i] == 0)
            flag = 1;
   // cout<<k<<" "<<flag<<" "<<cost<<endl;
    if( flag == 0)
    {
        ans = min(ans,cost);
    //    cout<<ans<<endl;
        return ;
    }
    if( k >= m)
        return ;
    for(int i=k;i<m;++i)
    {
        flag = 0;
        for(int j=0;j<n;++j)
        {
            if(taken[j] == 0 && M[i][j] == 1)
                flag = 1;
        }
        if( flag == 1)
        {
            for(int j=0;j<n;++j)
                taken[j]+=M[i][j];
            solve(i+1,cost+costi[i]);
            for(int j=0;j<n;++j)
                taken[j]-=M[i][j];
        }
        solve(i+1,cost);
    }
    return ;
}
int main()
{
    scan2(n,m);
    assert(n<21);
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
            cin>>M[i][j];
        cin>>costi[i];
    }
    ans = INFL;
    memset(taken,0,sizeof(taken));
    solve(0,0ll);
    cout<<ans<<endl;
    return 0;
}


