#include<bits\stdc++.h>
   
    using namespace std;  
	    class Graph
		{
	        	int n;
	        	vector <pair<int , int > > *g;
	        	int *parent;
	    	    int *distance;
	    	public:
	    		Graph(int n);
	    		void addedge(int u,int v,int w);
	    		void primalgo();
	    		void printMST();
	 	};
	 	struct compare
	    {
			bool operator()(const pair<int,int> l,const pair<int,int> r)
			{
				return l.second > r.second;
			}
			
			
		};
	 	
	 	Graph::Graph(int n)
		{
		    this->n = n;
			g = new vector<pair < int ,int > >[n] ;
		    parent = new int[n];
		    distance = new int[n];
			 	
		 	} 
		 	
		void Graph::addedge(int u,int v,int w)
		{
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
			 } 
			 
		void Graph::primalgo()
		{   bool *visited = new bool[n];
			for(int i =0;i<n;++i)
			{
				parent[i] = -1;
				distance[i] = INT_MAX;
				visited[i] = false;
			}
			priority_queue <int ,vector<pair<int,int> >, compare > Q;
			int src = 0;
			distance[src] = 0;
			Q.push(make_pair(src , distance[src]));
			vector< pair<int,int> > ::iterator i;
			pair<int,int> t;
			while(!Q.empty())
			{
				
			    t = Q.top();
				Q.pop();
				visited[t.first] = true;  
				  for(i = g[t.first].begin();i!= g[t.first].end(); ++i)
				  {
				  	  int v = (*i).first;
				  	  int weight = (*i).second;
				  	  
				  	  if( visited[v] == false && distance[v] > weight)
				  	  {
				  	  	    distance[v] = weight;
				  	  	    Q.push(make_pair(v,distance[v]));
				  	  	    parent[v] = t.first;
						}
				  }
			}
		}	
		
		void Graph::printMST()
		{
			printf("the MST of given graph is : \nu v weight\n");
			for( int i =1;i<n;++i)
			  printf("%d %d %4d \n",parent[i],i,distance[i]);
			 } 	
			 
		int main()
		{
			int V,E;
			FILE *prim = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\krus.txt","r");
			fscanf(prim,"%d %d",&V,&E);
			Graph g1(V);
			    for(int i =0;i<E;++i)
			     {
			     	int a,b,c;
			     	fscanf(prim,"%d %d %d",&a,&b,&c);
			     	g1.addedge(a,b,c);
				 }
				 
			  g1.primalgo();
			  g1.printMST();	 
			 }	 
