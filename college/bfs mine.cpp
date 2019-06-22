#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<limits>
    
    using namespace std;
     
        class Graph{
        	int n;
        	vector<int> *g;
        	int *distance;
        	int *parent;
        	public:
        		Graph(int n);
        		void addedge(int u,int v);
        		void BFS(int s);
        		void printgraph();
		};
		
		Graph::Graph(int n)
		{
			this->n = n;
			g = new vector<int> [n];
			distance = new int[n];
			parent = new int[n];
		}
		
		void Graph::addedge(int u,int v)
		{
			g[u].push_back(v);
		}
		
		void Graph::BFS(int s)
		{
			bool *visited = new bool[n];
			
			for(int i =0;i<n;++i)
			{
				visited[i] = false;
				distance[i] = INT_MAX;
				parent[i] = -1;
			}
			
			list<int> Q;
			
			visited[s] = true;
			Q.push_back(s);
			distance[s] = 0;
			vector<int>::iterator i;
			
			while(!Q.empty())
			{
				s = Q.front();
				Q.pop_front();
				
				for( i = g[s].begin();i!=g[s].end();++i)
				{
					if(!visited[*i])
					{
						visited[*i] = true;
						Q.push_back(*i);
						distance[*i] = distance[s] + 1;
						parent[*i] = s;	}
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
			int n;
			printf("enter the nodes of the graph : ");
			scanf("%d",&n);
			Graph g1(n);
			int e;
			printf("enter the number of edge in graph : ");
			scanf("%d",&e);
			int u,v;
			    for( int i = 0 ;i<e;++i)
			    {
			    	printf("enter the %d edge : ",i);
			    	scanf("%d %d",&u,&v);
			    	g1.addedge(u,v);
				}
		    printf("enter the starting point : ");
			scanf("%d",&u);		
			g1.BFS(u);
			printf("Following is the breadth first traversal starting from vertex: %d\n",u);
			g1.printgraph();
		
				
		}
		
		
		
		
