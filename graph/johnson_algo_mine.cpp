#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<limits>
#include<queue>

    using namespace std;
	struct Edge
	{
	    int start;
		int end;
		int weight;	
	};
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
        		void printgraph(int s,int dist[100]);
		};
		struct compare{
			bool operator()(const pair<int,int> l,const pair<int,int> r)
			{
				return l.second > r.second;
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
			//g[v].push_back(make_pair(u,w));
		}
		
		void Graph::Dijkstra(int s)
		{
			bool *visited = new bool[n];
			
			
			for(int i =0;i<n;++i)
			{
				visited[i] = false;
				distance[i] = INT_MAX;
				parent[i] = -1;
			}
			
		    priority_queue <pair<int,int> , vector<pair<int,int> > , compare> Q; 
			
			visited[s] = true;
			distance[s] = 0;
			Q.push(make_pair(s,distance[s]));
		//	distance[s] = 0;
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
					
				 //	printf("%d %d\n",distance[(*i).first] , distance[t.first] + (*i).second);
			    	if( distance[(*i).first] > distance[t.first] + (*i).second  )
					{
							 
						distance[(*i).first] = distance[t.first] + (*i).second;
						Q.push(make_pair((*i).first,distance[(*i).first]));
						parent[(*i).first] = t.first;
					
			    	}
						
							
						
				}
			} 
			
		}
		
		
		void Graph::printgraph(int s,int dist[100])
		{   printf("\n\nfrom %d vertix:\nvertex distance parent\n",s);
			for(int i =1;i<n;++i)
			{
				printf("%6d %8d %6d\n",i,distance[i] - dist[s] + dist[i]  ,parent[i]);
			}
		}
	int main()
	{
		int V,E;
		struct Edge* edge;
		FILE *john = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\johnson.txt","r");
		fscanf(john,"%d %d",&V,&E);
		edge = new struct Edge[E+V];
		int i;
			for(i=0;i<E;++i)
			{
				int u,v,w;
				fscanf(john,"%d %d %d",&u,&v,&w);
				edge[i].start = u;
				edge[i].end = v;
				edge[i].weight = w;
			}
			
			for(i=E;i<E+V;++i)
			{
				edge[i].start = 0;
				edge[i].end = i - E +1;
				edge[i].weight = 0;
			}
			
		//	for(i=0;i<E+V;++i)
		//	{
		//		printf("%d %d %d\n",edge[i].start,edge[i].end,edge[i].weight);
	//		}
			
		int distance[100] ,j;
			for(i=0;i<100;++i)
			{
				distance[i] = INT_MAX;
			}
		distance[0] = 0;	
			for( i =0 ; i< V;++i)
			{
				for(j=0;j<E+V;++j)
				{
				 	int u = edge[j].start;
					int v = edge[j].end;
				    int w = edge[j].weight;
				    if(distance[u] != INT_MAX && distance[u] + w < distance[v])
				    {
					    distance[v] = distance[u] + w;
					   // parent[v] = u;
					}	
				}
			}
				
			for(j=0;j<E;++j)
			{
				int u = edge[j].start;
				int v = edge[j].end;
				int w = edge[j].weight;
				if(distance[u] != INT_MAX && distance[u] + w < distance[v])
				{
					printf("the graph contain negative weight cycle\n");
					return 0 ;
				 }	
			}			
			
		//	for(i=1;i<V+1;++i)
		//	{
		//		printf("distance[%d] = %d\n",i,distance[i]);
		//	}
			Graph g(V+1);
			
			for(i=0;i<E+V;++i)
			{
				int u = edge[i].start;
				int v = edge[i].end;
				int w = edge[i].weight + distance[u] - distance[v];
		//		printf("w = %d\n",w);
				g.addedge(u,v,w);
			}
			
	    	for(i=1;i<V+1;++i)
	    	{
				g.Dijkstra(i);
				g.printgraph(i,distance);
		    } 
			
			return 0;
		
	}
	
		
	
