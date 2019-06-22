#include<stdio.h>
	long long int A[1000001] ;
	int main()
	{
		long long int n;
	
		scanf("%lld",&n);
		
		long long int i;
		    for(i=0;i<1000001;++i)
		    {
		    	 A[i]= 0;
			}
			for(i=0;i<n;++i)
			  {
			  	    long long int a;
			  	    scanf("%lld",&a);
			  	    A[a]++;
			  }
		//	for(i=100000;i<100010;++i)
		//	  printf("%lld= %lld\n",i,A[i])  ;
			for(i=1000000;i>0;--i)
			{
				if(A[i]%2 == 1 && A[i-1] > 0)
				{
					A[i]--;
					A[i-1]++;
				}
			}
			
			long long int count = 0;
		 //   for(i=100000;i<100010;++i)
		//	  printf("%lld= %lld\n",i,A[i])  ;
			long long int previous = 0;
			for(i=1000000;i>0;--i)
			{   
			    if(previous > 0 && A[i] > 1)
				{
					count = count + previous*i;
					A[i] = A[i] - 2;
					previous = 0;
				}
			    
			  //  printf("count = %lld, previous = %lld,i*p = %lld\n",count,previous ,i*previous);
			
				count = count + (A[i]/4)*i*i;
				A[i] = A[i]%4;
				
				if( A[i] >= 2)
				 previous = i;
				
					}
					
			printf("%lld",count);	
			return 0;	
	}
