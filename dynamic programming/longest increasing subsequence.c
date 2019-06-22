#include<stdio.h>
#include<stdlib.h>

	int lisdp(int A[1001],int n)
	{
		int *lis ;
		lis = malloc(n*sizeof(int ));
		int i;
		for(i=0;i<n;++i)
		{
			lis[i] =  1;
		}
		int j;
		for(i=0;i<n;++i)
		{
			for(j=0;j<i;++j)
			{
				if(A[i] > A[j] && lis[i] < lis[j] + 1)
					lis[i] =  lis[j] + 1;
			}
		}
		
		int max = 0;
		for(i=0;i<n;++i)
		{
			if(max < lis[i])
				max = lis[i];
		}
		
		free(lis);
		return max;
		
	}
	
	int main()
	{
		int n;
		scanf("%d",&n);
		int i;
		int A[1001];
		for(i=0;i<n;++i)
		{
			scanf("%d",&A[i]);
		}
		printf("%d\n",lisdp(A,n));
		return 0;
	}
