#include<iostream>
#include<vector>
#include<list>
#include<queue>

    
	using namespace std;
	 
	    class Graph
		{
	    	int V;
	    	vector <pair<int,int> > *g;
	        int *distance;
	        public:
	          Graph(int V);
	          void addedge(int u,int v,int w);
	          void Dijkstra(int n);
	          void print();
		};
		struct compare{
			bool operator()(const pair<pair<int,int>,pair<int,int> > l,const pair<pair<int,int>,pair<int,int> > r)
			{
				return l.second.second > r.second.second;
			}
			
			
		};
		Graph::Graph(int V)
		{
			this->V = V;
			g = new vector<pair<int,int> >[V];
			distance = new int[V];
		}
		void Graph::addedge(int u ,int v,int w)
		{
			g[u].push_back(make_pair(v,w));
		}
        void Graph::Dijkstra(int n)
        {
        	for(int i = 0 ;i<V;++i)
        	  distance[i] = 0;
        	  
        	int count = 0;
			priority_queue<int , vector<pair <pair<int,int> ,pair<int,int> > > ,compare> Q;
			for(int i=0;i<V;++i)
			 {
			 	  Q.push(make_pair(make_pair(i,g[i].front().first),make_pair(g[i].front().second,g[i].front().second)));
			 }
			 
			 while(count < n)
			 {
			 	pair<pair<int,int>, pair<int, int > > X;
			 	X = Q.top();
			 	Q.pop();
			 	//printf("%d %d %d %d\n",X.first.first,X.first.second,X.second.first,X.second.second);
			 	distance[X.first.first] = X.second.second;
			 	X.second.first = X.second.first + X.first.second;
			 	X.second.second =  X.second.second + X.second.first;
			 	count++;
			 	Q.push(make_pair(make_pair(X.first.first,X.first.second),make_pair(X.second.first,X.second.second)));
			 }
		  
		}
		void Graph::print()
		{   int MAX = distance[0];
			for(int i =1;i<V;++i)
			{
				 if(MAX < distance[i])
				  MAX = distance[i];
			}
			
			printf("%d\n",MAX);
		}

         int main()
        {
        	int T;
        	scanf("%d",&T);
        	while(T--)
        	{ 
    	        int n;
    	        scanf("%d",&n);
    	        int N;
    	        scanf("%d",&N);
    	        Graph g1(N);
    	   
    	            for(int i = 0;i<N;++i)
    	            {
    	              	int a;
    	             	scanf("%d",&a);
    	            	g1.addedge(i,a,a);
			         }
			    g1.Dijkstra(n);
				g1.print();     
			      
    		
		     }
		     return 0;
	    }
