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
int inner[lim],outer[lim],marked[lim];
vector<int> G[lim];
void DFS1(int ver,int par= 0)
{
    if( marked[ver] == 1)
        inner[ver] = 0;
    else
        inner[ver] = -1;
    for(auto child : G[ver])
    {
        if( child == par)
            continue;
        DFS1(child,ver);
        if( inner[child] > -1)
            inner[ver] = max(inner[ver],1+inner[child]);
    }
}
void DFS2(int ver,int par= 0)
{
    int m1 = -1,m2 = -1;
    for(int child : G[ver])
    {
        if( child == par)
            continue;
        if( inner[child] > m1)
        {
            m2 = m1;
            m1 = inner[child];
        }
        else if( inner[child] > m2)
            m2  = inner[child];
    }
    //cout<<ver<<m1<<m2<<endl;
    if(ver == 1 &&  marked[ver] == 1)
        outer[ver] = max(outer[ver],0);
    for(int child:G[ver])
    {
        if( child == par)
            continue;
        int temp ;
        if( inner[child] == m1)
            temp = m2;
        else
            temp = m1;
      //  cout<<"Temp "<<temp<<endl;
        if( temp != -1)
            temp+=2;
        if( outer[ver] != -1)
            temp = max(temp,outer[ver]+1);
        outer[child] = max(outer[child],temp);
        if( marked[child] == 1)
            outer[child] = max(outer[child],0);
        DFS2(child,ver);
    }
}

int main()
{
    memset(marked,0,sizeof(marked));
    memset(inner,-1,sizeof(inner));
    memset(outer,-1,sizeof(outer));
    int n,m,d;
    scan3(n,m,d);
    for(int i=0;i<m;++i)
    {
        int a;
        cin>>a;
        marked[a] = 1;
    }
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        scan2(a,b);
        G[a].pb(b);
        G[b].pb(a);
    }
    DFS1(1);
    DFS2(1);
    int cont = 0;
    for(int i=1;i<=n;++i)
        if( outer[i] <= d && inner[i] <= d)
            cont++;//cout<<i<<outer[i]<<inner[i]<<endl;
    cout<<cont<<endl;
    return 0;
}


