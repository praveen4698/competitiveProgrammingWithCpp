#include<bits\stdc++.h>
  
    using namespace std;
    
       class Graph
	   {
       	    int V;
			list<int> *g,*gt;
			public:
			Graph(int V);
			void addedge(int u,int v);
			void DFS(list<int> T[],int v,bool visited[]);
			bool SCG();
	   };
	   
	   Graph::Graph(int V)
	   {
	   	 this->V = V;
	   	 g = new list<int> [V];
	   	 gt = new list<int> [V];
	   }
	   
	   void Graph::addedge(int u,int v)
	   {
	   	    g[u].push_back(v);
	   	    gt[v].push_back(u);
	   }
	   
	   void Graph::DFS(list<int> T[],int v,bool visited[])
	   {
	   	    visited[v] = true;
	   	    
	   	    list<int> :: iterator i;
	   	    for(i = T[v].begin(); i!=T[v].end(); ++i)
	   	    {
	   	    	if(!visited[*i])
	   	    	    DFS(T,*i,visited);
			   }
	   }
	   
	   bool Graph::SCG()
	   {
	   	    bool visited[V] ;
	   	    
	   	        for(int i = 0; i <V;++i)
	   	            visited[i] = false;
	   	            
	   	    DFS(g,0,visited);
	   	    
	   	        for(int i =0; i<V;++i)
	   	            if(visited[i] == false)
	   	                return false;
	   	                
	   	        for(int i = 0 ; i<V;++i)
				    visited[i] = false;
					
			DFS(gt,0,visited);
			    
				for(int i =0; i<V;++i)
	   	            if(visited[i] == false)
	   	                return false;	
						   
				return true;		           
			       
	   }
	   
	   
	   int main()
	   { 
	   
	        int V;
	        scanf("%d",&V);
	        Graph g1(V);
	        int E;
	        scanf("%d",&E);
	        g1.addedge(0, 1);
            g1.addedge(1, 2);
            g1.addedge(2, 3);
	         
	        //  for(int i = 0;i<E;++i)
	        //  {
	          //	  int a,b;
	          //	  scanf("%d %d",&a,&b);
	          //	  g1.addedge(a,b);
	          	  
			 // }
	     
	        g1.SCG()? cout << "Yes\n" : cout << "No\n";
	   	    return 0;
	   }
