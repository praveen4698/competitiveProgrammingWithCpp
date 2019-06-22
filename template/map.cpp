#include<iostream>
#include<map>
#include<iterator>

    using namespace std;
     
        int main()
		{
			map < int , int >  g1;
			
			g1.insert(pair< int , int > ( 1, 40));
			g1.insert(pair< int , int > ( 2, 30));
			g1.insert(pair< int , int > ( 3, 60));
			g1.insert(pair< int , int > ( 4, 20));
			g1.insert(pair< int , int > ( 5, 50));
			g1.insert(pair< int , int > ( 7, 50));
			g1.insert(pair< int , int > ( 6, 10));
			
			map < int , int > :: iterator it ; 
			printf("the map g1 is : \n");
			printf(" KEY\tELEMENT\n");
		     	for(it = g1.begin(); it != g1.end(); ++it)
		    	{
		     		printf("%3d\t%7d\n",it->first,it->second);
		    	}
			
			printf("g1.lower_bound(5) : \n");
			printf("key : %d\n",g1.lower_bound(5)->first);
			printf("element : %d\n",g1.lower_bound(5)->second);
			printf("g1.upper_bound(5) : \n");
			printf("key : %d\n",g1.upper_bound(5)->first);
			printf("elements : %d\n",g1.upper_bound(5)->second);
			return 0;
		 } 
