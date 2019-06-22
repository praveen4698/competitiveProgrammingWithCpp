#include<iostream>
#include<stdio.h>
  
   using namespace std;
   
   void Zarr(string str, int Z[] );
   
   int  search(string pattern[1000000] , string text[1000000])
   {
   	     string concat = pattern + "$" + text ;
   	     int l = concat.length();
   	     int  count = 0;;
   	         int Z[l];
   	         Zarr(concat , Z);
   	         
   	         for(int i=1;i<l;++i)
   	         {
   	         	if(Z[i] == pattern.length())
   	         	{
   	         		count = count + 1;
					}
				}
   	 return count;
   }
   
   void Zarr(string str[100000],int Z[])
   {
   	     int n = str.length();
   	     int L,R,K;
         L = 0;
         R = 0;
         
         for(int i= 1;i<n;++i)
         {
         	if(i>R)
         	{
         		L = R = i;
         		while( R < n && str[R-L]==str[R])
         		{
         			R++;
         			 }
         	    Z[i] = R- L;
				 R--;		 
			 }
			 
			 else
			 {
			 	K = i-L;
			 	if(Z[K] < R-i+1 )
			 	  Z[i] = Z[K];
			 	  
			 	 else 
				  {
				  	L = i;
				  		while( R< n && str[R-L]==str[R])
         		{
         			R++;
         			 }
         	    Z[i] = R- L;
				 R--;
				  	
				   } 
			 }
         	
		 }
   }
   
   int main()
   {
   	
   }
