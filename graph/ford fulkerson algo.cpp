#include<iostream>
#include<string>
#include<queue>
#include<limits.h>
//#define V 6
    using namespace std;
        
		class graph
    	{
            	int V;
            	int **g;
            	int **rg;
            	int *parent;
    	    public:
    	    	graph(int V);
    	    	void addedge(int i,int j,int a);
    	    	bool BFS(int s,int t);
    	    	int fordfulkerson(int s,int t);
    		
	    };
	
    	graph::graph(int V)
     	{
	    	this->V = V;
	    	g = new int*[V];
	    	rg = new int*[V];
	    	parent = new int[V]; 
		       
			    for(int i = 0;i<V;++i)
		        {
		    	    g[i] = new int[V];
		        	rg[i] = new int[V]; 	
		    	}
		  
	    }
	
	    void graph::addedge(int i,int j,int a)
	    { 
	       g[i][j] = a;
       	}
       	
        bool graph::BFS(int s ,int t)
        {
        	bool visited[V];
        	
        	    for(int i = 0;i<V; ++i)
        	      visited[i] = false;
        	      
        	queue <int> q;
			q.push(s);
			visited[s] = true;
			parent[s] = -1;
			
			    while(!q.empty())
				{
					int u= q.front();
					q.pop();
					
					for(int i = 0 ; i < V; ++i)
					{
						if( visited[i] == 0 && rg[u][i] > 0)
						{
							q.push(i);
							parent[i] = u;
						    visited[i] = true;
						}
					}
		        } 
				
			return ( visited[t] == true) ;	     
		}
		
		int graph::fordfulkerson(int s,int t)
		{
			for(int i = 0;i<V;++i)
			    for(int j= 0 ;j< V;++j)
			       rg[i][j] = g[i][j];
			       
			int maxflow = 0;
			
			
			while( BFS(s,t))
			{
				int pathflow = INT_MAX;
				
				for(int i = t;i != s; i = parent[i])
				{
					pathflow = min( pathflow , rg[parent[i]][i]);
				}
				
				for(int i = t; i != s; i = parent[i])
				{
					 rg[parent[i]][i]-=pathflow;
					 rg[i][parent[i]]+=pathflow;
				}
				maxflow+=pathflow;
			}
			  
		     return maxflow;	       
		}
	    
	    
	    int main()
	    {   int V;
	       
	    	FILE *Graph = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\fordfulkerson.txt","r");
	    	//int V ;
	        fscanf(Graph,"%d",&V);
	        graph g1(V);
	     
	            for(int i = 0;i<V;++i) 
	                for(int j=0;j< V;++j)
	                {
	          	        int a ;
	          	        fscanf(Graph,"%d",&a);
	          	        g1.addedge(i,j,a);
			        }
			        
			    fclose(Graph);
			    int s,t;
				printf("enter the source and sink : ");
				scanf("%d %d",&s,&t);    
			    printf("maximum flow = %d",g1.fordfulkerson(s,t));
				return 0;    
		}
	
