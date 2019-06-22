#include<stdio.h>


    int main()
    {
    	int n;
    	scanf("%d",&n);
    	printf("+");
    	int i ;
    	for(i=0;i<2*n;++i)
    	  printf("-");
    	printf("+"); 
		int j;
		printf("\n");
		for(i=1;i <= n;++i)
		{
			printf("|");
			for(j=1;j<=n-i;++j)
			   printf(" ");
			 if(i<n)  
			 printf("/");
			 else printf("<");
			 if(i>1 && i%2 == 0){
			 
			 for(j=1;j < 2*i - 1 ;++j)
			   printf("-");}
			if(i>1 && i%2 == 1){
			 
			 for(j=1;j < 2*i - 1 ;++j)
			   printf("=");}
			   
			   
			   if(i<n)
			   printf("\\") ;
			   else printf(">");
			 for(j=1;j<=n-i;++j)
			   printf(" ");  
			printf("|");
			printf("\n");
		}
		for(i=n+1;i <= 2*n - 1;++i)
		{
			printf("|");
			for(j=1;j<=i-n;++j)
			   printf(" ");
		  
			 printf("\\");
			 
			 if(i>1 && i%2 == 0){
			 
			 for(j=1;j < 4*n - 2*i -1   ;++j)
			   printf("-");}
			if(i>1 && i%2 == 1){
			 
			 for(j=1;j < 4*n - 2*i-1  ;++j)
			   printf("=");}
			   
			   
			  printf("/");
			 for(j=1;j<=i-n;++j)
			   printf(" ");  
			printf("|");
			printf("\n");
		}
		
		printf("+");	
    	for(i=0;i<2*n;++i)
    	  printf("-");
    	printf("+");  
	}
