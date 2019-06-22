#include<iostream>
#include<stack>
   
    using namespace std;
      
       void showstack(stack<int> gq)
       {
       	    stack<int> g = gq;
       	    while(!g.empty())
       	    {
       	    	printf("%d ",g.top());
       	    	g.pop();
			   }
			 printf("\n");  
	   }
	   int main()
	   {
	   	 stack<int> gq;
	   	 gq.push(10);
	   	 gq.push(30);
	   	 gq.push(20);
	   	 gq.push(1);
	   	 gq.push(5);
	   	 gq.push(10);
	   	 printf("the gq stack is : ");
	   	 showstack(gq);
	   	 printf("gq.size() =  %d",gq.size());
	   	 return 0;
	   }
