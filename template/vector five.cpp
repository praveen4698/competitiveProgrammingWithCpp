#include<iostream>
#include<vector>
  
     using namespace std;
      
         int main(){
         	vector<int> g;
         	g.push_back(10);
         	g.push_back(20);
         	g.push_back(40);
         	  
         	  int sum = 0;
         	while(!g.empty())
         	{ 
         	  sum+=g.back();
         	  g.pop_back();
         	}
         	printf("sum = %d\n",sum);
         	return 0;
		 }
      
