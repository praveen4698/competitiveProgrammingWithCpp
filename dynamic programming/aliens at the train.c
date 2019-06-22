#include<stdio.h>
#include<limits.h>
   int A[1000000],count[1000000],station[1000000];
    int main()
    {   int t;
        scanf("%d",&t);
        while(t--)
        {
        	int n,limit,i,j;
        	scanf("%d",&n);
        	scanf("%d",&limit);
        	
        	for(i=0;i<n;++i)
        	{
        		A[i] = 0;
        		count[i] = 0;
        		station[i] = 0;
        		
			}
			
			for(i=0;i<n;++i)
			{
				scanf("%d",&A[i]);
			}
			j = 0;
			for(i=0;i<n;++i)
			{
				if(i>0)
				{
					  count[i] = count[i-1] - A[i-1];
					  station[i] = station[i-1] - 1;
					
				}
				while(j<n && count[i]+ A[j] <= limit )
				{
					count[i] = count[i]  + A[j];
					j++;
					station[i] = station[i] + 1;
				}
			}
			int maxs = 0;
			for(i=0;i<n;++i)
			{
				if(maxs < station[i])
				  maxs = station[i];
			 } 
			 int mincount = INT_MAX;
			 
			 for(i=0;i<n;++i)
			 {
			 	if(maxs == station[i] && mincount >= count[i])
			 	{
			 		mincount = count[i];
				 }
			 }
			 printf("%d %d\n",mincount,maxs);
		}
     return 0;
	   }
