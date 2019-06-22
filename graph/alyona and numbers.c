#include<stdio.h>

    int main()
    {
    	long long int n;
    	scanf("%lld",&n);
    	long long int m;
    	scanf("%lld",&m);
        long long int count = n * (m/5);
        m = m%5;
        count = count + m * (n/5);
        n = n%5;
        int i,j;
        for(i=1;i<m+1;++i)
           for(j=1;j<n+1;++j)
              if(i+j == 5)
                count++;
        
        printf("%lld",count);
        return 0;
	}
