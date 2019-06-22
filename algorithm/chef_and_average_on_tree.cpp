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
const int lim = 1e5+10;
int A[lim];
double B[lim],dp[lim][2];
vector<int> G[lim];
bool can;
int n;
void DFS(int ver,int par = -1)
{
    dp[ver][0] = dp[ver][1] = -1e10;
    vector<double> child,rchild;
    for(int g:G[ver])
    {
        if( g == par)
            continue;
        DFS(g,ver);
        if( dp[g][0] < 0)
            child.pb(dp[g][1]);
        else
            rchild.pb(dp[g][1]);
    }
    sort(all(rchild));
    reverse(all(rchild));
    int m = (int)child.size();
    if(m > 2)
    {
        can = false;
        return ;
    }
    if(m== 2)
    {
        if( child[1]+child[0]+B[ver] <0)
        {
            can = false;
            return;
        }
        dp[ver][0] = child[1]+child[0]+B[ver] ;
        dp[ver][1] = 0;
    }
    if(m == 1)
    {
        dp[ver][0] = child[0]+B[ver]+ (rchild.size()>0?max(0.0,rchild[0]):0.0);
        dp[ver][1] =  child[0]+B[ver];
    }
    if( m == 0)
    {
        dp[ver][1] = max(dp[ver][1],B[ver]+(rchild.size()>0?max(0.0,rchild[0]):0.0));
        dp[ver][0] = B[ver];
        dp[ver][0] += (rchild.size()>0?max(0.0,rchild[0]):0.0);
        dp[ver][0] += (rchild.size()>1?max(0.0,rchild[1]):0.0);
    }
    dp[ver][0] = max(dp[ver][0],dp[ver][1]);
    if( par == -1 && dp[ver][0] < 0)
    {
        can = false;
        return ;
    }
}
bool check(double x)
{

    for(int i=1;i<=n;++i)
        B[i] = 1.00*A[i]-x;
    can = true;
    DFS(1);
    return can;
}

int main()
{
    int t;
    scan(t);
    while(t--)
    {
        //int n;
        scan(n);
        double r,l =  1e-6 ;
        for(int i=1;i<=n;++i)
        {
            G[i].clear();
            cin>>A[i];
            r = max(r,1.00*A[i]);
        }
        for(int i=1;i<n;++i)
        {
            int a,b;
            scan2(a,b);
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=0;i<60;++i)
        {
            double m = (l+r)/2;
           // cout<<setprecision(20)<<l<<" "<<r<<" "<<m<<endl;
           // cout<<check(m)<<endl;
            if( check(m))
                l = m;
            else
                r = m;
        }
        printf("%.9f\n",(l+r)/2.0);
    }
    return 0;
}


