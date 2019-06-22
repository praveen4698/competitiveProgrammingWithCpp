#include<stdio.h>
#include<string.h>
  int main()
  {
  	int A[100]={0},i,C[100]={0};
  	char Str[100];
  	int flag =0;
  	printf("enter the expression : ");
  	scanf("%s",Str);
  	int n = strlen(Str);
  	int j=0;
  	for(i=0;i<n;++i)
  	{
  		C[i] =(int )Str[i] - '0';
  	
	  }
  	for(i=0;i<n;++i)
  	{
  		if(C[i]>= 0&& C[i] <= 9)
  		  {
  		  	A[j] =  (int )Str[i] -  '0' ;
  		 
  		  	j++;
			}
		 else if(j>1) 
		 {
		 	int a = A[j-1];
		 	int b = A[j-2];
		 	j = j-2;
		 	switch(Str[i])
		 	{
		 		case '+':
		 		 A[j] = b+a;
				  j++;
				 break; 
				 	case '*':
		 		 A[j] = b*a;
				  j++;
				 break; 
				 	case '-':
		 		 A[j] = b-a;
				  j++;
				 break; 
				 	case '/':
		 		 A[j] = b/a;
				  j++;
				 break; 	
			 }
			 }
			else 
			{  printf("error\n");
			    flag = 1;
				 }	
	  }
	  if( flag == 0)
	  printf("the result is : %d ",A[0]);
	  return 0;
  }
