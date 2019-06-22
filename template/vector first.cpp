#include<iostream>
#include<vector>
#include<stdio.h>
    
    using namespace std;
     
       int main()
       {
       	    vector <int> gi;
       	    vector <int> :: iterator i;
       	    vector <int> :: reverse_iterator ir ;
       	     
       	      
       	    for(int i = 1;i<=5;++i)
			    gi.push_back(i);
				
			printf("from beginning to end : ");	  
			for( i = gi.begin();i!=gi.end();++i)
			  printf("%d ",*i);
			printf("\n");
			printf("from last to first : ");
			for(ir = gi.rbegin();ir != gi.rend();++ir)
			  printf("%d ",*ir);  
			return 0;  
	   }
