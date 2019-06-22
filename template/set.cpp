#include<iostream>
#include<set>
#include<iterator>
   
    using namespace std;
    
        int main()
		{
			set< int , greater<int> > g1;
			g1.insert(40);
			g1.insert(30);
			g1.insert(60);
			g1.insert(20);
			g1.insert(50);
			g1.insert(50);
		    g1.insert(10);	
		     
		    set< int  > :: iterator itr;
			printf("the set g1 is  : ");
			
			for( itr = g1.begin();itr != g1.end(); ++itr)
			  {
			  	printf(" %d ", *itr);
			  }
			 printf("\n");
			 
			 set <int> g2(g1.begin(),g1.end());
			 
			 printf("the set g2 is : ");
			 for(itr = g2.begin();itr != g2.end(); ++itr)
			 {
			 	printf(" %d ", *itr);
			 }
			 printf("\n");
			 
			 g2.erase( g2.begin(),g2.find(30));
			 printf("the modified g2 is : ");
			 for(itr = g2.begin(); itr != g2.end();++itr)
			 {
			 	  printf(" %d ",*itr);
			 }
			 printf("\n");
			 
			printf("g1.lower_bound(40) : %d \n", *g1.lower_bound(40));
			printf("g1.upper_bound(40) : %d \n", *g1.upper_bound(40));
			printf("g2.lower_bound(40) : %d \n", *g2.lower_bound(40));
			printf("g2.upper_bound(40) : %d \n", *g2.upper_bound(40));
			 
			 
			 return 0;
		  }  
