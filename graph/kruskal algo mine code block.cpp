#include<iostream>
#include<algorithm>
#include<utility>
#include<stdio.h>

    using namespace std;

		bool compare(const pair< pair<int,int> ,int> l,const pair< pair<int,int> ,int> r)
	   	{
			return l.second < r.second;
	     }
		int find(int parent[],int i)
        {   if(parent[i] == -1)
              return i;

        	return find(parent , parent[i]);
	   	 }
        void Union(int parent[100],int rank[100],int x,int y)
		{
			int xi = find(parent,x);
			int yi = find(parent,y);

			  if(rank[xi] < rank[yi])
			   parent[xi] = yi;

			  else if(rank[xi] > rank[yi])
			    parent[yi] = xi;

			  else
			  {
			  	  parent[xi] = yi;
			  	  rank[xi]++;
				}

		}


        int  kruskal(int V,int E,pair< pair<int,int> ,int > edge[])
        {
        	pair< pair<int,int> ,int > *result ;
        	result = new pair< pair<int,int>, int>[E];
            int e=0,i=0;

            sort(edge,edge+E,compare);
        	int parent[V] ;
            int rank[V];

        	   for(i=0;i<V;++i)
        	    {
        	    	parent[i] = -1;
        	    	rank[i] = 0;
				}

			i =0;

			while(e<V-1)
			{
				pair< pair<int,int> , int > next = edge[i++];

				int x = find(parent,next.first.first);
				int y = find(parent,next.first.second);

				   if( x != y)
				   {
        		   	    result[e++] = next;
		    	   	    Union(parent,rank,x,y);
				   }

				}

			printf("minimum spanning tree of the above graph : \n");

			for(i=0;i<V-1;++i)
			 printf("%d -- %d = %d\n",result[i].first.first,result[i].first.second,result[i].second);

		}
        int main()
        {
        	 int V,E;
        	// printf("enter the vertices : ");
        	FILE* krus = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\krus.txt","r");
        	fscanf(krus,"%d",&V);
        	// scanf("%d",&V);
        	// printf("enter the number the edges : ");
        	 fscanf(krus,"%d",&E);
        	 pair< pair<int,int> ,int > edge[E];

        	    for(int i=0;i<E;++i)
        	    {
        	    	 //printf("enter the start point , end point and weight of the first edge : \n");
        	    	 fscanf(krus ,"%d %d %d",&edge[i].first.first,&edge[i].first.second,&edge[i].second);
				}
				fclose(krus);
			int n = kruskal(V,E,edge);
			return 0;

		}
