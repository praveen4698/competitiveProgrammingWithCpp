#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e6;
multiset<ll> S;
vector<int> cost[lim];
int parent[lim],sum[lim];
vector<pair<int,int> > edge;
vector<pair<char,pair<int,int> > > query;
vector<int> ans;
int par(int x)
{
    cout<<"as"<<endl;
    if( parent[x] == -1)
        return x;
    return (parent[x] = par(parent[x]));
}
int main()
{
    int n,m,q;
    S3(n,m,q);
    for(int i=1;i<=n;++i)
    {
        int a;
        S(a);
        cost[i].push_back(a);
    }
    for(int i=0;i<m;++i)
    {
        int a,b;
        S2(a,b);
        edge.push_back({a,b});
    }
    for(int i=0;i<q;++i)
    {
        char a;
        int b,c;
        cin>>a;
        if( a == 'D')
        {
            S(b);
            query.push_back({a,{b,-1}});
        }
        else
        {
            S2(b,c);
            query.push_back({a,{b,c}});
            cost[b].push_back(c);
        }
    }
    reverse(query.begin(),query.end());
    memset(parent,-1,sizeof(parent));
    for(int i=1;i<=n;++i)
    {
        S.insert(*cost[i].rbegin());
        sum[i] = *cost[i].rbegin();
    }

    for(auto q:query)
    {
        ans.push_back(*S.rbegin());
        char c = q.first;

        if( c == 'D')
        {
            cout<<"sas1"<<endl;
            int x = edge[q.second.first].first;
            int y = edge[q.second.first].second;
            int fx = par(x);
            int fy = par(y);
            int flag = 0;
            if( fy == fx)
            {
                flag = 1;
            }
            if( flag == 0)
            {

            cout<<"in"<<endl;
            S.erase(S.find(1ll*sum[fx]));
            cout<<"in2"<<endl;
            S.erase(S.find(1ll*sum[fy]));

            sum[fx]+=sum[fy];
            sum[fy] = sum[fx];
            S.insert(1ll*sum[fx]);
            cout<<"out2"<<endl;
            parent[fy] = fx;
            }
            cout<<"sas"<<endl;
        }
        else
        {

            int x = q.second.first;
            int fx  = par(x);
            cout<<"asaf"<<endl;
            int oldvalue = *cost[x].rbegin();
            cout<<"insaf"<<endl;
            cost[x].pop_back();
            cout<<"in32"<<endl;
            int newvalue = *cost[x].rbegin();
            cout<<"in33"<<endl;
            S.erase(S.find(1ll*sum[fx]));
            cout<<"asfsa54"<<endl;
            sum[fx] = sum[fx] - oldvalue + newvalue;
            S.insert(1ll*sum[fx]);
            cout<<"sa1"<<endl;

        }

    }
    reverse(ans.begin(),ans.end());
    for(int a:ans)
        cout<<a<<endl;
    return 0;
}
