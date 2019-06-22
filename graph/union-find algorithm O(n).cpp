#include<iostream>
#include<vector>
#include<utility>
  
    using namespace std;
        int find(int parent[],int i)
        {   if(parent[i] == -1)
              return i;
          
        	return find(parent , parent[i]);
		}
		void Union(int parent[100],int x,int y)
		{
			int xi = find(parent,x);
			int yi = find(parent,y);
			parent[xi] = yi;
		}
         int cycle(int V,int E,pair<int,int> edge[100])
        { 
            int parent[V];
                
                for(int i=0;i<V;++i)
                  parent[i] = -1;
		    
		        for(int i=0;i<E;++i)
		        {
		        	int x = find(parent,edge[i].first);
		        	int y = find(parent,edge[i].second);
		         //  for(int j=0;j<V;++j)
		         //    printf("parent[%d] = %d\n",j,parent[j]);
		        	if( x == y) 
		        	   return 1;
		        	   
		        	Union(parent,x,y);   
				}
		
		     return 0;
         	
		}
        int main()
        {
        	int E,V;
        	printf("enter the number of vertices : ");
            scanf("%d",&V);
            printf("enter the number of edge :  ");
            scanf("%d",&E);
            pair<int,int> edge[E];
            
                for(int i = 0;i<E;++i)
                {
                	printf("enter the first edge : ");
                	scanf("%d %d",&edge[i].first,&edge[i].second);
				}
			
			int n = cycle(V,E,edge)	;
			printf("%d\n",n);   
			    if(n==1)
			       printf("YES\n");
			    else 
				  printf("NO\n");
				  
			return 0;	     
            
		}
 
  
