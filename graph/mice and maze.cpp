#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<limits>
#include<queue>
#include<stdio.h>

    
    using namespace std;
   
        class Graph{
        	int n;
        	vector<pair<int,int> > *g;
        	int *distance;
        
        	int *dis;
        	public:
        		Graph(int n);
        		void addedge(int u,int v,int w);
        		void Dijkstra(int s,int end);
        	    void printresult( int t);
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
		
			dis = new int[n];
		}
		
		void Graph::addedge(int u,int v,int w)
		{
			g[u].push_back(make_pair(v,w));
		
		}
		
		void Graph::Dijkstra(int s,int end)
		{
			bool *visited = new bool[n];
			
			
			for(int i =0;i<n;++i)
			{
				visited[i] = false;
				distance[i] = 1000000000;
				
			}
			
		     priority_queue <int , vector<pair<int,int> > , compare> Q; 
			
			visited[s] = true;
			distance[s] = 0;
			Q.push(make_pair(s,distance[s]));
			distance[s] = 0;
			vector<pair<int,int> >::iterator i;
			pair<int,int> t;
			while(!Q.empty())
			{
				t = Q.top();
				Q.pop();
			//	printf("%d %d\n",t.first,t.second);
				for( i = g[t.first].begin();i!=g[t.first].end();++i)
				{
					if(!visited[(*i).first])
					{
						visited[(*i).first] = true;
					
						distance[(*i).first] = distance[t.first] + (*i).second ;
						Q.push(make_pair((*i).first,distance[(*i).first]));
							}
					
					
				  //  printf("t.first = %d\n",t.first);
				//	printf(" distance[%d] = %d\n",(*i).first,distance[(*i).first]);
				//	printf("distance[%d]+ %d = %d\n\n",t.first,(*i).second,distance[t.first] + (*i).second);	
			    	if( distance[(*i).first] >= distance[t.first] + (*i).second  )
					{
							 
						distance[(*i).first] = distance[t.first] + (*i).second;
					
					//	Q.push(make_pair((*i).first,distance[(*i).first]));	
			    	}
						
							
						
				}
			
			}
		//	printf(" %d  %d\n",end,distance[end]);
			dis[s] = distance[end];
			
		}
		
		void Graph::printresult(int t)
		{    int count =0;
			for(int i=1;i<n;++i)
			 {
			 	if(dis[i] <= t)
			 	  count++;
			 }
			 printf("%d\n",count);
		}
	
		
		int main()
		{
			int n;
			scanf("%d",&n);
			Graph g1(n+1);
			int t;
			int end;
			scanf("%d",&end);
			scanf("%d",&t);
			int e;
			scanf("%d",&e);
			int u,v,w;
			    for( int i = 0 ;i<e;++i)
			    {
			    
			    	scanf("%d %d",&u,&v);
			    
			    	scanf("%d",&w);
			    	g1.addedge(u,v,w);
				}
		   
		    for(int i=1;i<n+1;++i)	
			g1.Dijkstra(i,end);
		    g1.printresult(t);
		
		
		    return 0;		
		}
	
