#include<iostream>
#include<stack>
#include<queue>
#include<vector>


    using namespace std;
    
 		class Graph
		{
	    	int V;
			vector<pair<int,int> > *adj;
			stack<int> Stack;
			public:
				Graph(int v);
				void addEdge(int u,int v,int w);
				void shortestdistance(int s);
				void topologicalsort(int u,bool visited[100]);
					
		};
		
		Graph::Graph(int v)
		{
			V = v;
			adj = new vector<pair<int,int> > [V];
			//Stack = new stack<int>;
		}
		
		void Graph::addEdge(int u,int v,int w)
		{
			adj[u].push_back(make_pair(v,w));
		}
		void Graph::topologicalsort(int u,bool visited[100])
		{
			    visited[u] = true;
			   
			    vector<pair<int,int> >::iterator it;
			   		for(it = adj[u].begin();it != adj[u].end();it++)
					 {
					 	 if(!visited[(*it).first])
					 		topologicalsort((*it).first,visited);
						}	   
			    Stack.push(u);
			    return ;
		}
		void Graph::shortestdistance(int s)
		{
			bool *visited = new bool [V];
				for(int i = 0;i<V;++i)
				{
					visited[i] = false;
				}
				
				for(int i = 0;i<V;++i)
				{
					if(!visited[i])
					  topologicalsort(i,visited);
				}
				
			int dist[100];
			
				for(int i = 0 ; i<V;++i)
				{
					dist[i] = INT_MAX;
				}
			
			dist[s] = 0;
			vector<pair <int,int> >::iterator it;		
				while(!Stack.empty())
				{
					int t = Stack.top();
				    Stack.pop();
				//	printf("%d\n",t);
				    if(dist[t] != INT_MAX)
				    {
				    	for(it = adj[t].begin();it != adj[t].end(); ++it)
				    	{
				    		if(dist[(*it).first] > dist[t] + (*it).second )
				    			dist[(*it).first] = dist[t] + (*it).second;
						}
					}
				    
				    	
				}
				
				for(int i=0;i<V;++i)
				{   
				    
					printf("vertex = %d distance = %d\n",i,dist[i]);
				}
				return;
		}
		int main()
		{
			int V,E;
			FILE *shortest = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\shortest_distance.txt","r");
			fscanf(shortest,"%d %d",&V,&E);
			Graph g(V);
				
				for(int i = 0;i<E;++i)
				{
					int u,v,w;
					fscanf(shortest,"%d %d %d",&u,&v,&w);
					g.addEdge(u,v,w);
				}
				g.shortestdistance(5);
		}
