#include<stdio.h>
#include<limits.h>
    void Floyd_warshall(int Graph[100][100],int V )
    {
    	int i,j,k;
    	int distance[100][100];
    	    for(i=0;i<V;++i)
    	        for(j=0;j<V;++j)
    	          distance[i][j] = Graph[i][j]; 
    	          
    	    for(k=0;k<V;++k)
			    for(i=0;i<V;++i)  
				    for(j=0;j<V;++j)
					{
						if(distance[i][k] + distance[k][j] < distance[i][j])
						   distance[i][j] = distance[i][k] + distance[k][j];
						}  
			printf("the distance between each pair is : \n"); 			
		    for(i=0;i<V;++i)
			   {
				for(j=0;j<V;++j)
				  {  if(distance[i][j] == 1000)
				     printf("MAX ");
				     else
				     printf("%3d ",distance[i][j]);}
				   
				
				printf("\n");   
			}
	}
    int main()
    {
    	
    	int V;
    	int Graph[100][100];
    	int i,j ;
    	    for(i=0;i<100;++i)
    	       for(j=0;j<100;++j) 
    	          Graph[i][j] = 1000;
    	printf("enter the number of vertices : ");
		scanf("%d",&V);
		int E;
		printf("enter the number of edges : ");
		scanf("%d",&E);
		int a ,b ,w;
		    for(i=0;i<E;++i)
			 {
			    printf("enter the start point , end point and weight of the %d edge  : ",i+1);
				scanf("%d %d %d",&a,&b,&w);
				Graph[a][b] = w;
					
			   }  
	    Floyd_warshall(Graph,V);
		return 0;	           
	}
