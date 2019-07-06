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
        ll dist[lim];
        vector<pair<int,ll> > g[lim];
        struct compare
        {
            bool operator()(const pair<int,ll> l,const pair<int,ll> r)
			{
				return l.S > r.S;
			}


		};
        void Dijkstra(int s)
		{
			priority_queue <pair<int,ll> , vector<pair<int,ll> > , compare> Q;
            Q.push(make_pair(s,dist[s]));
			vector<pair<int,ll> >::iterator i;
			pair<int,ll> t;
			while(!Q.empty())
			{
				t = Q.top();
				Q.pop();

				for( i = g[t.first].begin();i!=g[t.first].end();++i)
				{


			    	if( dist[(*i).first] > dist[t.first] + (*i).second  )
					{

						dist[(*i).first] = dist[t.first] + (*i).second;
						Q.push(make_pair((*i).first,dist[(*i).first]));


			    	}

                }
			}

		}
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            int n,k,x,m,s;
            scan2(n,k);
            scan3(x,m,s);
            lp(i,0,n+1)
            {
                g[i].clear();
                dist[i] = INFL;
            }
            lp(i,0,m)
            {
                int a,b,c;
                scan3(a,b,c);
                g[a].pb(mp(b,(ll)c));
                g[b].pb(mp(a,(ll)c));
            }
            if( s <= k)
            {
                lp(i,1,k+1)
                {   if( i == s) continue;
                    g[s].pb(mp(i,(ll)x));
                    g[i].pb(mp(s,(ll)x));
                }
                dist[s] = (ll)0;
                Dijkstra(s);
                lp(i,1,n+1)
                    printf("%lld ",dist[i]);
            }
            else
            {
                dist[s] =(ll)0;
                Dijkstra(s);
                ll mini = INFL;
                int ver = 0;
                lp(i,1,k+1)
                {
                    if( dist[i] < mini)
                    {
                        mini = dist[i] ;
                        ver = i;
                    }
                }
                lp(i,1,k+1)
                {
                    if( i == ver) continue;
                    g[ver].pb(mp(i,(ll)x));
                    g[i].pb(mp(ver,(ll)x));
                }
                Dijkstra(ver);
                lp(i,1,n+1)
                    printf("%lld ",dist[i]);
            }
            printf("\n");
        }
        return 0;
    }
