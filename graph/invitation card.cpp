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
static const int INF = 0x3f3f3f3f;
static const long long int  INFL = 0x3f3f3f3f3f3f3f3fLL;
    vector<pair<long long int,long long  int> > g[1000001];
    vector<pair<long long int,long long  int> > gr[1000001];
    long long int dist[1000001];
    bool visited[1000001];
    long long int V,E;
		struct compare
		{
			bool operator()(const pii l,const pii r)
			{
				return l.S > r.S;
			}
        };

		void Dijkstra(long long int s)
		{



			for(int i =0;i<V+1;++i)
			{
				visited[i] = false;
				dist[i] = INFL;

			}

		     priority_queue <pair<long long int,long long int> , vector<pair<long long int,long long int> > , compare> Q;

			visited[s] = true;
			dist[s] = 0;
			Q.push(make_pair(s,dist[s]));
			vector<pair<long long int,long long int> >::iterator i;
			pair<long long int,long long int> t;
			while(!Q.empty())
			{
				t = Q.top();
				Q.pop();

				for( i = g[t.F].begin();i!=g[t.F].end();++i)
				{


			    	if( dist[(*i).F] > dist[t.F] + (*i).S  )
					{

						dist[(*i).F] = dist[t.F] + (*i).S;
						Q.push(make_pair((*i).F,dist[(*i).F]));

			    	}



				}
			}

		}

        void Dijkstra2(long long int s)
		{



			for(int i =0;i<V+1;++i)
			{
				visited[i] = false;
				dist[i] = INFL;

			}

		     priority_queue <pair<long long int,long long int> , vector<pair<long long int,long long int> > , compare> Q;

			visited[s] = true;
			dist[s] = 0;
			Q.push(make_pair(s,dist[s]));
			dist[s] = 0;
			vector<pair<long long int,long long int> >::iterator i;
			pair<long long int,long long int> t;
			while(!Q.empty())
			{
				t = Q.top();
				Q.pop();

				for( i = gr[t.F].begin();i!=gr[t.F].end();++i)
				{


			    	if( dist[(*i).F] > dist[t.F] + (*i).S  )
					{

						dist[(*i).F] = dist[t.F] + (*i).S;
						Q.push(make_pair((*i).F,dist[(*i).F]));

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

                scan(V);
                scan(E);
                lp(i,0,E)
                {
                    //printf("yo2\n");
                    long long int a,b,c;
                    scanf("%lld %lld %lld",&a,&b,&c);
                    g[a].push_back(mp(b,c));
                    gr[b].push_back(mp(a,c));
                }
                Dijkstra(1);
               // printf("yo\n");
                long long int count = 0;
                lp(i,1,V+1)
                    count = count + dist[i];
                Dijkstra2(1);
                lp(i,1,V+1)
                    count = count + dist[i];
                printf("%lld\n",count);
                lp(i,0,V+1)
                {
                    gr[i].clear();
                    g[i].clear();
                }

            }

		    return 0;
		}
