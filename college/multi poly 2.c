  #include<stdio.h>
  #include<stdlib.h>
  #include<math.h>
  
   int main()
   {
   	  int n,i,A[100] = {0},B[100]= {0},nn,C[200]={0};
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
		 int j;
		 for(i=0;i<=nn;++i)
		 {
		 	for(j=0;j<=n;++j)
		 	{
		 		C[i+j]= C[i+j] + B[i]*A[j];
			 }
		 }
		 int max = n+nn;
		 for(i=max;i>=0;i--)
		 {  if( C[i]>0)
		 	printf("+%dx^%d ",abs(C[i]),i);
		 	if(C[i]<0)
		 	printf("-%dx^%d ",abs(C[i]),i);
		 }
	   	 
   	  return 0;
   }
