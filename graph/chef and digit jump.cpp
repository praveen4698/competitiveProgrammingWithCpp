#include<iostream>
#include<vector>
#include<list>
#include<cstring>
   
    using namespace std;
        int A[100001];
        class Graph{
        	int V;
        	vector<int> *g;
        	int *distance;
        	 public:
        	 	Graph(int V);
        	 	void addedge(int u,int v);
        	 	void BFS(int t);
		};
		
		Graph::Graph(int V)
		{
			this->V = V;
			g = new vector<int>[V];
			distance = new int[100001];
		}
		
		void Graph::addedge(int u,int v)
		{
			g[u].push_back(v);
		}
		void Graph::BFS(int t)
		{  
		    for(int i =0;i<t;++i)
			  {
			  	distance[i] = 1000000000;
				  }	
				  
		    list <int> q;
			distance[0] = 0;
			q.push_back(0);	
			bool visited[10];
			for(int i=0;i<10;++i)
			  visited[i] = false;
			int n;
			vector <int> :: iterator it;
			while(!q.empty())
			{
				n = q.front();
				q.pop_front();
				if(visited[A[n]] == false)
				{
					for(it = g[A[n]].begin();it != g[A[n]].end();++it)
					{
						if(distance[*it] > distance[n] + 1)
						  {
						  	distance[*it] = distance[n] + 1;
						  	q.push_back(*it);
						  }
					}
					visited[A[n]] = true;
				}
				
				if(distance[n+1] > distance[n] + 1 && n+1 <= t-1)
				{
					distance[n+1] = distance[n] +1;
					q.push_back(n+1);
				}
				if(distance[n-1] > distance[n] + 1 && n-1 >= 0)
				{ 
				    distance[n-1] = distance[n] + 1;
				    q.push_back(n-1);
				    
				}
			  } 
			  
			  printf("%d",distance[t-1]); 
		}
      
        int main()
        {
            char str[100001];
			scanf("%s",str);
			Graph g(10);
			int t = strlen(str);
			   
			    for(int i =0;i<t;++i)
				 {
				 	A[i] = str[i] - '0';
				 	g.addedge(A[i],i);
					 }	
					 
			if( str[0] == str[t-1])
			{
				if(t==1)
				  printf("0");
				else
				  printf("1");
			}
			else
			{
				g.BFS(t);
			}
		return 0;	 		 
		}
   
