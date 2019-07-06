#include<stdio.h>
 int A[100][100];
  
int count( int S[], int m, int n )
{
   if(A[m][n] != -1)
   {
   	 return A[m][n];
   }
    
	else{
	if (n == 0)
        return 1;
     
  
    if (n < 0)
        return 0;
 
    if (m <=0 && n >= 1)
        return 0;
     A[m-1][n] = count(S,m-1,n) ;
     A[m][n - S[m-1]] = count(S,m,n-S[m-1]);
    return A[m-1][n] + A[m][n - S[m-1]];}
}
 

int main()
{
    int i, j;
    int arr[] = { 2, 3,5,6};
    for(i=0;i<100;++i)
     for(j=0;j<100;++j)
     {
     	A[i][j] = -1;
	 }
    int m = sizeof(arr)/sizeof(arr[0]); 
    printf("%d ", count(arr, m, 10));
    getchar();
    return 0;
}

