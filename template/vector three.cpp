#include<iostream>
#include<vector>
#include<string>
   
    using namespace std;
      
        int main()
		{
			vector <int> g1;
			
			for(int i = 0;i<=10;++i)
			   g1.push_back(i*10);
			   
			 printf("reference operator : %d\n",g1[2]);
			 printf("at : g1.at(4) = %d\n",g1.at(4));
			 printf("front() : %d\n",g1.front());
			 printf("back() : %d\n",g1.back());
			 return 0;  
			}    
