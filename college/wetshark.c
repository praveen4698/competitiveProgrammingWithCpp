#include<stdio.h>
#include<limits.h>
  
     int main()
     {
        long long int n;
     	scanf("%lld",&n);
     	long long int i;
     	long long int a,min = INT_MAX;
     	long long int  sum = 0 ;
     	for( i = 0;i<n;++i)
     	{
     		scanf("%lld",&a);
     		sum = sum + a;
     		if( a%2 == 1 && min > a)
     		  min = a;
		 }
		 if(sum%2 == 1)
		  sum = sum - min;
		  
		printf("%lld",sum);
		return 0;
		  
	 }
