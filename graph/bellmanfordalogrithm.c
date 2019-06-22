#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
        
		struct Edge{
			int start,end,weight;
		}; 
	     int  bellmanford(int V,int E,struct Edge edge[100],int src)
		{  
		    int distance[100] ;
		    int i;
		    for(i=0;i<100;++i)
		     distance[i] = INT_MAX;
		    int parent[100] = {-1};
			distance[src]= 0;
			int  j;
			    
				for( i =0 ; i< V-1;++i)
				{
				 	for(j=0;j<E;++j)
				 	{
				 	   int u = edge[j].start;
					   int v = edge[j].end;
					   int w = edge[j].weight;
					   if(distance[u] != INT_MAX && distance[u] + w < distance[v])
					     {
					     	distance[v] = distance[u] + w;
					     	parent[v] = u;
							 }	
					 }
				}
				
				for(j=0;j<E;++j)
				{
				    int u = edge[j].start;
					int v = edge[j].end;
					int w = edge[j].weight;
					if(distance[u] != INT_MAX && distance[u] + w < distance[v])
					{
					    printf("the graph contain cycle\n");
					 }	
				}
				
				printf("vertex distance parent\n");
				for(i=0;i<V ;++i)
				{
					printf("%6d %8d %6d\n",i,distance[i],parent[i]);
				}
		
					
				}
		int main()
		{
		    struct Edge *edge;
			int V;
			int E;
			printf("enter the number vertices : ");
			scanf("%d",&V);
			printf("enter the number edges : ");
			scanf("%d",&E);
			edge = (struct Edge*)malloc(E*sizeof(struct Edge));
			int i;
			    
			    for(i=0;i<E;++i)
			    {   printf("enter the start point , end point and weight of the %d edge : ",i);
			    	scanf("%d %d %d",&edge[i].start,&edge[i].end,&edge[i].weight);
				}
			printf("enter the start point : ");
			int src;
			scanf("%d",&src);
			bellmanford(V,E,edge,src)	;
			return 0;
			 	
		}
