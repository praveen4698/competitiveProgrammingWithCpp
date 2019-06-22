#include<iostream>
#include<vector>
#include<list>
#include<utility>
#include<limits>
#include<stdio.h>
    
    using namespace std;
        int A[3001][3001] ;
        class Graph{
        	int n;
        	vector<int> *g;
        	int *distance;
        	int *parent;
        	public:
        		Graph(int n);
        		void addedge(int u,int v);
        		int BFS(int s,int *j1,int mark[]);
        		void printgraph();
        		//void worldtour();
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
			//g[v].push_back(u);
		}
		
		int  Graph::BFS(int s,int *j1,int mark[])
		{
			bool *visited = new bool[n+1];
			
			for(int i =0;i<n;++i)
			{
				visited[i] = false;
				distance[i] = -1;
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
			int max = 0;
			for(int i = 1; i<n+1;++i )
			{
				if(distance[i] > max && mark[i] == 0  )
				{
					max = distance[i];
					*j1 = i;
				}
			}
			if(*j1 == 0)
			return INT_MIN;
			else
			return max;
			
		}
		
		
		void Graph::printgraph()
		{   printf("vertex distance parent\n");
			for(int i =0;i<n;++i)
			{
				printf("%6d %8d %6d\n",i,distance[i],parent[i]);
			}
		}
		
		void worldtour(Graph g1,int n)
		{
		//	int i;
			int *mark = new int[n+1];
				for(int i =0;i<n+1;i++)
				{
					mark[i] = 0;
				}
				int finalmax = 0;
				int path[4] = {0};
				for(int i = 1;i<n+1;++i)
				{   
				    int j1=0;
				    mark[i] = 1;
				    int max = g1.BFS(i,&j1,mark);
				    int j2=0;
				    mark[j1] = 1;
				    int max1 = g1.BFS(j1,&j2,mark);
				     mark[j2] = 1;
				    int j3 = 0;
				   
				    int max2 = g1.BFS(j2,&j3,mark);
				     mark[j3] = 1;
				    if( finalmax < (max + max2 + max1))
				    {
				    	finalmax = max + max1 + max2;
				    	path[0] = i;
				    	path[1] = j1;
				    	path[2] = j2;
				    	path[3] = j3;
					}
					mark[i] = 0;
					mark[j1] = 0;
					mark[j2] = 0;
					mark[j3] = 0;
				for(int i=0;i<4;++i)
				{
					printf("%d %d %d %d %d\n",i,j1,j2,j3,max+max1+max2);
				}
				printf("\n");
				} 
				for(int i=0;i<4;++i)
				{
					printf("%d %d\n",path[i],finalmax);
				}
		}
		int main()
		{
			int n;
		//	printf("enter the nodes of the graph : ");
			scanf("%d",&n);
			Graph g1(n+1);
			int e;
		//	printf("enter the number of edge in graph : ");
			scanf("%d",&e);
			int u,v;
			
			for(int i = 0;i<3001;++i)
			    for(int j = 0;j < 3001;++j)
			    {
			    	if(i ==j)
			    	 A[i][j] = 1;
			    	else
			    	 A[i][j] = 0;
				}
			    for( int i = 0 ;i<e;++i)
			    {
			    //	printf("enter the %d edge : ",i);
			    	scanf("%d %d",&u,&v);
			    	if(A[u][v] == 0)
			        	g1.addedge(u,v);
				}
		  //  printf("enter the starting point : ");
		//	scanf("%d",&u);		
		    worldtour(g1,n);
		//	printf("Following is the breadth first traversal starting from vertex: %d\n",u);
		//	g1.printgraph();
		
		    return 0;		
		}
		
