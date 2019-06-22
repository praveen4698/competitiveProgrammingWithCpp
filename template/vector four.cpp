#include<iostream>
#include<vector>
  
    using namespace std;
      
        int main()
        {
        	vector<int>  g1;
        	vector<int>  g2;
        	vector<int>  g3;
        	
        	   g1.assign(5,10);
        	   
        	vector<int> :: iterator it;
			it = g1.begin();
			
			    g2.assign(it +1,g1.end() - 1);
			
			int a[] = {1,2};
			     g3.assign(a,a+2);
				 
				 
			printf("size of g1 : %d\n",(g1.size()));
			printf("size of g2 : %d\n",int(g2.size()));
			printf("size of g3 : %d\n",int(g3.size()));
			return 0;	 	   
		}
