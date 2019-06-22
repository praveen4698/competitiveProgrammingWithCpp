#include<stdio.h>
#include<stdlib.h>
   
    struct node{
    	int row,col,value;
	};
	int compare(const void *A ,const void *B)
	{
		return( (*(struct node *)A).row - (*(struct node *)B).row );
	}
	int main()
	{
		int i,n;
		int Row,Col;
		printf("enter number the rows and column of given matrix : ");
		scanf("%d %d",&Row,&Col);
		printf("enter number of non zero elements of sparse matrix : ");
		scanf("%d",&n);
		struct node *A = (struct node*)malloc(n*sizeof(struct node));
	      	for(i=0;i<n;++i)
	    	{
	 		printf("enter the row column and value of %d element : ",i+1);
			scanf("%d %d %d",&A[i].col,&A[i].row,&A[i].value);
			
		    }
		qsort(A,n,sizeof(struct node),compare);
		printf("the transpose of given matrix is : \n");
		printf("row column value \n");
		for(i=0;i<n;++i)
		{
			printf("%3d %6d %5d \n",A[i].row,A[i].col,A[i].value);
		}
		return 0;
		
	}
