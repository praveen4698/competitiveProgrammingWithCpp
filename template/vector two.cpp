#include<iostream>
#include<vector>
#include<stdio.h>
   
    using namespace std;
      
        int main()
        {
        	vector <int> gi;
        	
        	for(int i = 0;i<=32;++i)
        	  gi.push_back(i);
        	  
        	printf("size : %d\n",gi.size());
			printf("capacity : %d\n",gi.capacity());
			printf("max_size : %lld\n",gi.max_size());
			return 0;  
        	
		}
