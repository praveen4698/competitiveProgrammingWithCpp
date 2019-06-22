#include<iostream>
#include<list>
	using namespace std;
		
		class Graph
		{
			int V;
			list <int> *adj;
			public:
				Graph(int V);
				void addedge(int u,int v);
				void coloring();
		};
		
		
		Graph::Graph(int V)
		{
			this->V = V;
			adj = new list<int> [V];
		}
		
		void Graph::addedge(int u,int v)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void Graph::coloring()
		{
			int result[V];
			bool used[V];
			
				for(int i = 0;i<V;++i)
				{
						used[V] = false;
						result[i] = -1;
				}
			//	result[0] = 0;	
				for(int i = 0;i<V;++i)
				{
					list<int> :: iterator j;
					for(j = adj[i].begin();j != adj[i].end();++j)
						if(result[*j] != -1)
							used[result[*j]] = true;
							
					int cr;
					for(cr = 0;cr<V;++cr)
						if(used[cr] == false)
							break;
					
					result[i]= cr;
					
					for(j = adj[i].begin();j != adj[i].end();++j)
						if(result[*j] != -1)
							used[result[*j]] = false;
									
				}
				
				for(int i = 0;i<V;++i)
					printf("%d %d\n",i,result[i]);	
		}
		
		int main()
		{
			int V,E;
			FILE  *color  = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\coloring.txt","r");
			fscanf(color,"%d %d",&V,&E);
			Graph g(V);
			for(int i = 0 ;i<E;++i)
			{   
			    int u,v;
				fscanf(color,"%d %d",&u,&v);
				g.addedge(u,v);
			}
			g.coloring();
			fclose(color);
			return 0;
		}
