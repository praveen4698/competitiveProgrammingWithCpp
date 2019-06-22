#include<stdio.h>
#include<string.h>
#include<stdlib.h>

	void LPS_array(char pattern[1001],int M,int lps[1001])
	{
		int len = 0;
		int i = 1;
		lps[0] =0;
		
		while(i<M)
		{
			if(pattern[i] == pattern[len])
			{
				len++;
				lps[i] = len;
				i++;
			}
			
			else
			{
				if(len != 0)
				{
					len = lps[len -1]; //most important step
				}
				else
				{
					lps[i] = 0;
					i++;
				}
			}
		}
	}
	int KMP_algo(char text[1001],char pattern[1001])
	{
		int M = strlen(pattern);
		int N = strlen(text);
		
		int *lps = malloc(M*sizeof(int));
		int j= 0;
		
		LPS_array(pattern,M,lps);
		
		int i = 0;
		
		while(i<N)
		{
			if(pattern[j] == text[i])
			{
				j++;
				i++;
			}
			
			if(j == M)
			{
				printf("found the pattern at %d \n",i-j);
				j = lps[j-1];
			}
			
			else if(i<N && pattern[j] != text[i])
			{
				if(j != 0)
				 j = lps[j-1];
				else
				 i = i+1; 
			}
		}
		
		free(lps);
	}
	


	int main()
	{
		char text[1001];
		char pattern[1001];
		FILE *K = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\KMP.txt","r");
		fscanf(K,"%s",text);
		fscanf(K,"%s",pattern);
		KMP_algo(text,pattern);
		fclose(K);
	}
