#include<iostream>
#include<algorithm>
#include<stdio.h>
  
      using namespace std;
        
          void show(int a[])
           {
           	 for(int i = 0;i<10;++i) 
           	   printf("%d ",a[i]);
           	   printf("\n");
		   }
		   int main()
		   {
		   	 int a[]= { 1,5,8,9,6,7,3,4,2,0};
		   	 printf("without sort : ");
		   	 show(a);
		   	 sort(a,a+10);//sort(start address , end address)
		   	 printf("with sort : ");
		   	 show(a);
		   	 return 0;
		   }
