#include<stdio.h>
#include<stdlib.h>
   int A[1000][1000];
    
   int max(int a,int b) 
   {
        return a>b?a:b;
		}
   int Knapsack(int w,int wt[],int val[],int n)
    {
    	if(n==0||w==0)
    	  return 0;
    	A[w][n-1] = Knapsack(w,wt,val,n-1); 
    	if(wt[n-1]>w)
		  return A[w][n-1];
		A[w - wt[n-1]][n-1] = Knapsack(w-wt[n-1],wt,val,n-1);
		return max(val[n-1] + A[w - wt[n-1]][n-1],A[w][n-1]);   
	}
	int main()
	{      
	    int val[] = {60,100,120};
	    int wt[] = {10,20,30};
	    int w = 50;
	    int n = 3;
	    printf("%d\n",Knapsack(w,wt,val,n));
	    return 0;
	}
    
   
