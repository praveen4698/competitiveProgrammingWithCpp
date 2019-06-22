#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<limits>
#include<queue>

    using namespace std;
	class Graph
	{
		int V;
		vector<int> *adj;
		public:
			Graph(int v);
			void addEdge(int u,int v);
			bool bipartite();
	};
	
	Graph::Graph(int v)
	{
		this->V = v;
		adj = new vector<int> [V]; 
	}
	
	void Graph::addEdge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool Graph::bipartite()
	{
		int color[V];
			
			for(int i=0;i<V;++i)
			{
				color[i] = -1;
			}
			
		color[0] = 0;
		queue <int> q;
		q.push(0);
	    vector<int>::iterator it;		
			while(!q.empty())
			{
				int a = q.front();
				q.pop();
				printf("color[%d] = %d\n",a,color[a]);
				for(it = adj[a].begin();it != adj[a].end();++it)
				{
					if(color[*it] == -1)
					{
						color[*it] = 1 - color[a];
						q.push(*it);
					}
					else if( color[*it] == color[a])
					{
						return false;
					}
				}
				
			}
			
			return true;
				
	}
	int main()
		{
			int V,E;
			FILE  *bi  = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\bipartite.txt","r");
			fscanf(bi,"%d %d",&V,&E);
			Graph g(V);
			for(int i = 0 ;i<E;++i)
			{   
			    int u,v;
				fscanf(bi,"%d %d",&u,&v);
				g.addEdge(u,v);
			}
			if(g.bipartite())
				printf("true\n");
			else
				printf("false\n") ;
			fclose(bi);
			return 0;
		}

	
	

