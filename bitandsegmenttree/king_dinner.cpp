#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1001;
vector<int> G[lim];
int dist[lim],cont[2];
bool DFS(int ver,int dis,int par=-1)
{

    if(dist[ver] == -1)
        dist[ver] = dis,cont[dis]++;
    else if( dist[ver] != dis)
        return false;
    else if( dist[ver] == dis)
        return true;
     for(auto a:G[ver])
     {
         if(a == par)
            continue;
         if( DFS(a,1-dis,ver) == false)
         {

             return false;

         }
     }

     return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    int x = 1;
    while(t--)
    {
        int n;
        memset(dist,-1,sizeof(dist));
        memset(cont,0,sizeof(cont));
        for(int i=0;i<lim;++i)
            G[i].clear();
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int a;
            scanf("%d",&a);
            for(int j=0;j<a;++j)
            {
                int b;
                scanf("%d",&b);
                G[i].push_back(b);
            }
        }
        int flag = 0;
        for(int i=1;i<=n;++i)
        {
            bool tt = true;
            if( dist[i] == -1)
                tt = DFS(i,0);
            if( tt == false)
            {
                flag = 1;
                printf("Case %d: 0 0 0\n",x);
                break;
            }
        }
        if(flag == 0)
            printf("Case %d: 1 %d %d\n",x,min(cont[0],cont[1]),max(cont[0],cont[1]));

        x++;
    }
    return 0;
}
