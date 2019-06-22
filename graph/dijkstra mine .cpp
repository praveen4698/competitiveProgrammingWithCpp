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

    using namespace std;

        class Graph
		{
        	int n;
        	vector<pair<int,int> > *g;
        	int *distance;
        	int *parent;
        	public:
        		Graph(int n);
        		void addedge(int u,int v,int w);
        		void Dijkstra(int s);
        		void printgraph();
		};
		struct compare{
			bool operator()(const pair<int,int> l,const pair<int,int> r)
			{
				return l.S > r.S;
			}


		};

		Graph::Graph(int n)
		{
			this->n = n;
			g = new vector<pair<int,int> >[n];
			distance = new int[n];
			parent = new int[n];
		}

		void Graph::addedge(int u,int v,int w)
		{
			g[u].push_back(make_pair(v,w));
		//	g[v].push_back(make_pair(u,w));
		}

		void Graph::Dijkstra(int s)
		{
			bool *visited = new bool[n];


			for(int i =0;i<n;++i)
			{
				visited[i] = false;
				distance[i] = 100000000;
				parent[i] = -1;
			}

		     priority_queue <pair<int,int> , vector<pair<int,int> > , compare> Q;

			visited[s] = true;
			distance[s] = 0;
			Q.push(make_pair(s,distance[s]));
			distance[s] = 0;
			vector<pair<int,int> >::iterator i;
			pair<int,int> t;
			while(!Q.empty())
			{
				t = Q.top();
				Q.pop();

				for( i = g[t.first].begin();i!=g[t.first].end();++i)
				{
				/*	if(!visited[(*i).first])
					{
						visited[(*i).first] = true;

						distance[(*i).first] = distance[t.first] + (*i).second ;
						Q.push(make_pair((*i).first,distance[(*i).first]));
						parent[(*i).first] = t.first;	}

					*/

			    	if( distance[(*i).first] > distance[t.first] + (*i).second  )
					{

						distance[(*i).first] = distance[t.first] + (*i).second;
						Q.push(make_pair((*i).first,distance[(*i).first]));
						parent[(*i).first] = t.first;

			    	}



				}
			}

		}


		void Graph::printgraph()
		{   printf("vertex distance parent\n");
			for(int i =0;i<n;++i)
			{
				printf("%6d %8d %6d\n",i,distance[i],parent[i]);
			}
		}

		int main()
		{
			int V;
			FILE *dij = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\krus.txt","r");
			//printf("enter the nodes of the graph : ");
			fscanf(dij,"%d",&V);
			Graph g1(V);
			int e;
		//	printf("enter the number of edge in graph : ");
			fscanf(dij,"%d",&e);
			int u,v,w;
			    for( int i = 0 ;i<e;++i)
			    {
			    	//printf("enter the %d edge  : ",i);
			    	fscanf(dij,"%d %d",&u,&v);
			    	//printf("weight of the edge : ");
			    	fscanf(dij,"%d",&w);
			    	g1.addedge(u,v,w);
				}
		    printf("enter the starting point : ");
			scanf("%d",&u);
			g1.Dijkstra(u);
			printf("shortest distance of each vertix from vertex: %d\n",u);
			g1.printgraph();

		    return 0;
		}

