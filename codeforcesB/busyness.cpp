#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vector<pair<pair<int,int>,int > > edge;
    const int lim = 1e6;
    int parent[lim],s[lim];
    vector<int> G[lim];
    struct comp
    {
        bool operator() (const pair<pair<int,int>,int >& lhs, const pair<pair<int,int>,int > & rhs) const
        {
            return lhs.second<rhs.second;
        }
    };
    struct comp1
    {
        bool operator() (const pair<ll,int >& lhs, const pair<ll,int > & rhs) const
        {
            return (lhs.first>rhs.first || (lhs.first == rhs.first && lhs.second<rhs.second));
        }
    };

    int par(int x)
    {
        if(parent[x] == -1)
            return x;
        return parent[x] = par(parent[x]);
    }
    int DFS(int ver,int per=-1)
    {
        s[ver] = 1;
        parent[ver] = per;
        int temp = 0;
        for(auto u:G[ver])
        {
            if(u == per)
                continue;
            temp+=DFS(u,ver);
        }
        s[ver]+=temp;
        return s[ver];
    }
    vector<pair<ll,int> > ans;
    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        memset(parent,-1,sizeof(parent));
        memset(s,0,sizeof(s));
        for(int i=0;i<m;++i)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            edge.push_back({{a,b},c});
        }
        sort(edge.begin(),edge.end(),comp());

        for(auto a:edge)
        {
           // printf("%d %d %d\n",a.first.first,a.first.second,a.second);
            int x = a.first.first;
            int y = a.first.second;
            int fx = par(x);
            int fy = par(y);
            if( fx == fy)
            {
                continue;
            }
            else
            {
                parent[fx] = fy;
               // printf("%d %d \n",x,y);
                G[x].push_back(y);
                G[y].push_back(x);

            }

        }
        memset(parent,-1,sizeof(parent));
        DFS(1);
        for(int i=1;i<=n;++i)
        {
            ll temp = 0;
            //printf("size i = %d %d \n",i,s[i]);
            for(auto j:G[i])
             {
                 if( parent[j] == i)
                    temp+=(s[j]*1ll*(n-s[j]-1));
                else
                    temp+=((n-s[i])*1ll*(s[i]-1));
             }
            ans.push_back({temp,i});
           // printf("%lld %d\n",temp,i);
        }
        sort(ans.begin(),ans.end(),comp1());
        for(auto a:ans)
            cout<<a.second<<"\n";
        return 0;
    }
