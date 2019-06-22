#include<stdio.h>
#include<stdlib.h>
 int A[1001][1001];
  
     int main()
     {
     	int n;
     	int a,b;
     	int i,j;
     	for(i = 0;i < 1001 ;++i)
     	  for(j = 0; j < 1001; ++j)
     	      A[i][j] = 0;
     	scanf("%d",&n);
     	for(i = 0;i < n; ++i)
     	{
     		scanf("%d %d",&a,&b);
			 A[a][b]++;		 }
	    long long int count = 0,tempcount=0;
		int k;
		for(i=1;i<1001;++i)
		{    j =i;
	         k= 1;
	         tempcount = 0;
			 while( j <= 1000 && k <=1000)
			 {
			 	  if(A[k][j] == 1)
			 	    tempcount++;
			 	    j++;
			 	    k++;
	 				  }	
	     	count = count +  (tempcount) * (tempcount -1) /2;			   
					      	}
				for(i=2;i<1001;++i)
	        	{    k =i;
	                j= 1;
	               tempcount = 0;
		         	 while( j <= 1000 && k <=1000)
			      {
			 	  if(A[k][j] == 1)
			 	    tempcount++;
			 	    j++;
			 	    k++;
					  }	
	             	count = count +  (tempcount) * (tempcount -1) /2;			   
					      	}		      	
				 
				for(i=1000;i>0;--i)
	         	{       j =i;
	                   k= 1;
	                  tempcount = 0;
		           	 while( j > 0 && k <=1000)
			        {
			 	      if(A[k][j] == 1)
			 	      tempcount++;
			 	          j--;
			 	         k++;
	 			     	  }	
	     	         count = count +  (tempcount) * (tempcount -1) /2;			   
					      	}
			    for(i=999;i>0;--i)
	                 	{    k = 1001 - i;
	                      j= 1000;
	                   tempcount = 0;
		             	 while( j > 0 && k <=1000)
			          {
			 	        if(A[k][j] == 1)
			 	        tempcount++;
			 	             j--;
			 	            k++;
					  }	
	             	count = count +  (tempcount) * (tempcount -1) /2;			   
					      	}		      	
				 printf("%lld\n",count);
				 return 0;
	 }
