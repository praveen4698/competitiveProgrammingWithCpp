#include<iostream>
#include<algorithm>
#include<stdio.h>
     using namespace std;
	int main()
	{
		int n;
		scanf("%d",&n);
		int A[100001];
		
			for(int i = 0;i<n;++i)
			{
				scanf("%d",&A[i]);
			}
			
		sort(A,A+n);
		int count = 0;
		
			for(int i =0;i<n;++i)
			{
				if(A[i] > count)
				  count++;
			}
			
			printf("%d",count+1);
			return 0;
	}
