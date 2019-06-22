#include<stdio.h>
#include<string.h>

	int max(int a,int b)
	{
		return a>b?a:b;
	}

	int lcs_dp(char A[200], char B[200])
	{
		int n = strlen(A);
		int m = strlen(B);
		int lcs[m+1][n+1];
		
		int i,j;
		for(i=0;i<=m;++i)
		{
			for(j=0;j<=n;++j)
			{
				if(i==0||j == 0)
					lcs[i][j] = 0;
					
				else if( A[j-1] == B[i-1])
					lcs[i][j] =  1 + lcs[i-1][j-1];
				
				else
					lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);		
			}
		
		}
			return lcs[m][n];
	}
	
	int main()
	{
		char A[200];
		char B[200];
		scanf("%s",A);
		scanf("%s",B);
		printf("%d\n",lcs_dp(A,B));
		return 0;
	}
