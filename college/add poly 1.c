  #include<stdio.h>
  #include<stdlib.h>
  #include<math.h>
  
   int main()
   {
   	    int n,i,A[100] = {0},B[100]= {0},nn;
   	    printf("enter maximum power of first polynomial : ");
   	    scanf("%d",&n);
   	    
		   for(i=n;i>=0;i--)
   	       {
   	       	printf(" enter coefficient of x^%d : ",i);
   	     	scanf("%d",&A[i]);
   	    	printf("\n");
	      	}
	 printf("enter maximum power of second polynomial : ");
   	  scanf("%d",&nn);
   	  for(i=nn;i>=0;i--)
   	  {
   	  	printf(" enter coefficient of x^%d : ",i);
   	  	scanf("%d",&B[i]);
   	  	printf("\n");
		 }
		 int max = n>nn?n:nn;
		 for(i=max;i>=0;i--)
		 {  if( A[i]+B[i]>=0)
		 	printf("+%dx^%d ",abs(A[i]+B[i]),i);
		 	else
		 	printf("-%dx^%d ",abs(A[i]+B[i]),i);
		 }
	   	 
   	  return 0;
   }
