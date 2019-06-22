#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
        int dist[100001];
        vi G[100001],Rg[100001];
     	struct compare{
			bool operator()(const pair<int,int> l,const pair<int,int> r)
			{
				return l.S > r.S;
			}


		};

    int main()
    {
        priority_queue <pair<int,int> , vector<pair<int,int> > , compare> Q;
        int n,m;
        scan(n);
        scan(m);
        lp(i,0,n+1)
        {
            dist[i] = INF;
        }
        lp(i,0,m)
        {
            int a,b;
            scan(a);
            scan(b);
            G[a].pb(b);
            Rg[b].pb(a);
        }
        dist[1] = 0;
        Q.push(mp(1,0));
        while(!Q.empty())
        {
            pair<int,int> t = Q.top();
            Q.pop();
            int father = t.F;
            int dis = t.S;
            vector<int> :: iterator i;
            for(i = G[father].begin();i!= G[father].end();++i)
            {
                if( dist[*i] > dis)
                {
                    dist[*i] = dis;
                    Q.push(mp(*i,dis));
                }
            }
            for(i = Rg[father].begin();i!=Rg[father].end();++i)
            {
                if( dist[*i] > dis+1)
                {
                    dist[*i] = dis+1;
                    Q.push(mp(*i,dist[*i]));
                }
            }


        }

        if( dist[n] == INF)
           printf("-1\n");
        else
            printf("%d\n",dist[n]);
        return 0;
    }

