
#include<stdio.h>
 int A[100][100];

int binomialCoeff(int n, int k)
{  if(A[n][k] != -1)
      {  return A[n][k];
             }
  
  if (k==0 || k==n)
    return 1;
   
   A[n-1][k-1] = binomialCoeff(n-1, k-1);
   A[n-1][k] =  binomialCoeff(n-1, k);
  return A[n-1][k] + A[n-1][k-1];
}
 

int main()
{
    int n = 5, k = 2;
    int i,j;
    for(i=0;i<100;++i)
    {
    	for(j=0;j<100;++j)
    	{
    		A[i][j] = -1;
		}
	}
    printf("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k));
    return 0;
}
