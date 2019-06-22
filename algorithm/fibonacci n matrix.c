#include<stdio.h>
#define T 1000000007

    void multiply(long long int F[2][2],long long int M[2][2])
    {
    	long long int x =  F[0][0]*M[0][0]%T + F[0][1]*M[1][0]%T;
        long long int y =  F[0][0]*M[0][1]%T + F[0][1]*M[1][1]%T;
        long long int z =  F[1][0]*M[0][0]%T + F[1][1]*M[1][0]%T;
        long long int w =  F[1][0]*M[0][1]%T + F[1][1]*M[1][1]%T;
 
          F[0][0] = x%T;
          F[0][1] = y%T;
          F[1][0] = z%T;
          F[1][1] = w%T;
	}
    void power(long long int F[2][2] ,long long int n)
    {
    	long long int i;
    	long long int M[2][2] = {{1,1},{1,0}};
    	
    	    for(i=2;i<=n;i++)
    	      multiply( F,M);
	}
    long long int fib(long long int n)
    {
    	if( n== 0)
    	{
    		return 0;
		}
		
		long long int F[2][2] = {{1,1} , { 1,0}};
		power(F,n-1);
		return F[0][0];
		
	}
    int main()
    {
    	 int n;
    	 n = 9;
    	 printf("%lld",fib(1000000000));
    	 return 0;
	}
