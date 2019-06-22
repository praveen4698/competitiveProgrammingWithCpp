#include<stdio.h>
    long long int A[101];
    int fib(int n)
    {
    	if( A[n] == -1)
    	{
    		if(n <= 1)
    			A[n] = n;
    		else
    			A[n] = fib(n-1) + fib(n-2);
		}
		return A[n];
	}
	int main()
	{
		int i;
		for(i=0;i<101;++i)
		{
			A[i] = -1;
		}
		int n;
		scanf("%d",&n);
		printf("%lld",fib(n));
		return 0;
		
	}
