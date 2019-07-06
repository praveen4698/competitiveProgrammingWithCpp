#include<stdio.h>
#include<stdlib.h>
    long long int dp[1000001] = {0},A[1000001] = {0};
    long long int max(long long int a,long long int b)
    {
    	return a>b?a:b;
	}
    long long int boredomdp(int n )
    {   
    	dp[0]= 0;
    	dp[1] = A[1] ;
    	
    
	
    	int i;
    	for(i=2;i<=n;++i)
    	{
    	   long  long int a = dp[i-1];
    	  long 	long int b = dp[i-2] + A[i]*i;
    		dp[i] = max(a,b);
    	
		}
	
		return dp[n];
	
	}
     int main()
     {
     	long long int n,i;
     	scanf("%lld",&n);
        long long int a;
     	for(i=0;i<n;++i)
     	{
     		scanf("%lld",&a);
     		A[a]++;
		 }
		
		 n =1000000;
		 long long int count = boredomdp(n);
		 printf("%lld\n",count);
		 return 0;
	 }
