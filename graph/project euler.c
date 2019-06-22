#include<stdio.h>

	int main ()
	{
		int i ;
		long long int count = 0;
		long long int A[100]= {0};
		A[0] = 1;
		A[1] = 1;
		A[2] = 2;
		i = 2;
		while( A[i-1] <= 40000000)
		{
			A[i] = A[i-1] + A[i-2];
			if(i%2 == 0)
				count = count + A[i];
			
			//printf("%lld\n",A[i]);
			i++;
		}
		printf("%lld",count);
		return 0;
	}
