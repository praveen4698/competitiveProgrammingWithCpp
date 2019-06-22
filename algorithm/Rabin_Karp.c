#include<stdio.h>
#include<string.h>

#define d 256
#define q 1000000007

	void Rabin_algo(char text[1001],char pattern[1001])
	{
		int M = strlen(pattern);
		int N = strlen(text);
		long long int i,j;
		long long int p=0,t=0;
		long long int h = 1;
		
		for(i=0;i<M-1;++i)
			h = (h*d)%q;
			
		for(i=0;i<M;++i)
		{
			p = ((p*d)%q + pattern[i])%q;
			t =  ((t*d)%q + text[i])%q;
		 } 
		// printf("%lld \n",p);
		for(i=0;i<=N-M;++i)
		{   
		//    printf("%lld  %lld\n",i,t);
			if(p == t)
			{
				for(j=0;j<M;++j)
				{
					if(pattern[j] != text[i+j])
						break;
				}
				
				if( j == M)
					printf("pattern found at %d\n",i);
			}
			
			if(i < N-M)
			{
				t = ((t - (h*text[i])%q)*d + text[i+M])%q;
				
				if( t < 0)
				t = t+q;
			}
		}
	}
	
	int main()
	{
		char text[1001];
		char pattern[1001];
		FILE *K = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\KMP.txt","r");
		fscanf(K,"%s",text);
		fscanf(K,"%s",pattern);
		Rabin_algo(text,pattern);
		fclose(K);
	}	
