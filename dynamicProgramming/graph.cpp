#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5 + 10;
    map<string,int> M;
    vpii G[lim];
    vector<pair<pair<int,int>,pair<int,int> > > sus;
    bool valid[lim],visit[lim];
    int dist[lim];
    int parent[lim];
    int findp(int i)
    {
        if(parent[i] == i)
            return parent[i];
        parent[i] = findp(parent[i]);
        return parent[i];

    }
    void dfs(int node,int pnode,int x)
    {
        visit[node]=1;
        dist[node]=x;
        for (int i=0;i<G[node].size();i++)
        {
            if (G[node][i].first!=pnode)
            dfs(G[node][i].first,node,(x^G[node][i].second));
        }
    }
    void preprocess(int n)
    {
        for (int i=0;i<n;i++)
        {
            if (!visit[i])
            dfs(i,i,0);
        }
        for (int i=0;i<sus.size();i++)
        {
            int x=sus[i].first.first,y=sus[i].first.second,idx=sus[i].second.first,r=sus[i].second.second;
            if ((dist[x]^dist[y])==r)
                valid[idx]=true;
            else
                valid[idx]=false;
        }
    }
    int main()
    {
        int n,m,q,t;
        string s,s2;
        scan3(n,m,q);
        lp(i,0,n)
        {
            parent[i] = i;
            cin>>s;
            M[s] = i;
        }
        lp(i,0,m)
        {
            cin>>t>>s>>s2;
            int x = M[s];
            int y = M[s2];
            int fx = findp(x);
            int fy = findp(y);
            if( fx != fy)
            {
                parent[fx] = fy;
                G[x].pb(mp(y,t-1));
                G[y].pb(mp(x,t-1));
                valid[i] = true;
            }
            else
                sus.pb(mp(mp(x,y),mp(i,t-1)));

        }

        preprocess(n);
        lp(i,0,m)
        {
            if( valid[i])
                cout<<"YES";
            else
                cout<<"NO";

            printf("\n");
        }
        while(q--)
        {
            cin>>s>>s2;
            int x = M[s];
            int y = M[s2];
            if( findp(x) != findp(y))
                cout<<3;
            else if (dist[x]^dist[y])
            cout << 2 ;
            else
            cout << 1 ;


            printf("\n");
        }

        return 0;
    }


