#include<stdio.h>
    
    void printheap(int heap[100],int a)
    {
    	int i;
    	for(i=0;i<a;++i)
    	{
    		printf("%d ",heap[i]);
		}
	}
	
	int  extractmin(int heap[101],int a )
	{
		if( a == 0)
		{
			return heap[0];
		 }
		 
		int b = heap[0];
		heap[0] = heap[a] ;
		heap[a] = -1;
		int j=0;
		while( j <= a && heap[j] != -1 ) 
		{
			if( heap[2*j + 1] != -1 && heap[2*j +2]  != -1)
			{
				if(heap[2*j +1] < heap[2*j + 2] && heap[j] > heap[2*j + 1] )
				{
					int temp = heap[2*j + 1];
					heap[2*j + 1] = heap[j] ;
					heap[j] = temp;
					j = 2*j +1;
				}
				else if(heap[2*j +1] > heap[2*j + 2] && heap[j] > heap[2*j + 2] ) 
				{
					int temp = heap[2*j + 2];
					heap[2*j + 2] = heap[j] ;
					heap[j] = temp;
					j = 2*j +2;
				}
				else break;
			}
			else if( heap[2*j + 1] > -1 && heap[2*j +2]  == -1)
			{
				if(heap[2*j +1] < heap[j] )
				{
					int temp = heap[2*j + 1];
					heap[2*j + 1] = heap[j] ;
					heap[j] = temp;
					j = 2*j +1;
				}
				else break;
			}
			
			else if( heap[2*j + 1] == -1 && heap[2*j +2]  > -1)
			{
				if(heap[2*j +2] < heap[j] )
				{
					int temp = heap[2*j + 2];
					heap[2*j + 2] = heap[j] ;
					heap[j] = temp;
					j = 2*j +2;
				}
				else break;
			}
			else break;
		}
		return b;
	}
    int main()
    {
    	int heap[101];
    	int i;
    	for(i=0;i<101;++i)
    	{
    		heap[i] = -1;
		}
		
		int a;
	//	printf("enter the no elements in heap : ");
		FILE *heapi = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\heap.txt","r");
		fscanf(heapi,"%d",&a);
		  
		    for(i=0;i<a;++i)
		    {
		    	int b;
		    	//printf("enter the %d element of heap : ",i);
		    	fscanf(heapi,"%d",&heap[i]);
		    	int j = i;
		    	while( j > 0 )
		    	{
		    		 if(heap[j] < heap[(j-1)/2])
		    		 {
		    		 	int temp = heap[j];
		    		 	 heap[j] = heap[(j-1)/2];
		    		 	 heap[(j-1)/2] = temp;
					 }
					 j = (j-1)/2 ;
					 				}
			}
			
			printf("heap array : ");
			printheap(heap,a);
			printf("\n");
		//	printf("\nsorted array : ");
			for(i=a-1;i>=0;--i)
			{
				int b = extractmin(heap,i);
				printf("extracted item : %d \n",b);
				printf("remaining array : ");
				printheap(heap,i);
				printf("\n");
			}
		return 0;	
	}
